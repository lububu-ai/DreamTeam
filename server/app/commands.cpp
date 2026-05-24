#include "commands.h"

/**
 * @file commands.cpp
 * @brief Определение функций, реализующих бизнес-логику ответов сервера на команды протокола.
 */

/**
 * @details Проверяет наличие всех необходимых параметров регистрации, обращается к инстансу
 * базы данных и пытается добавить пользователя. Возвращает текстовый статус операции.
 */
QString register_user(QStringList args, int socket_descriptor)
{
    Database* db = Database::getInstance();
    if (args.size() >= 4){
        if(db->is_reg_ok(args[1], args[2], args[3], socket_descriptor)) {
            return "reg_success user\r\n";
        }
    }
    return "reg_fail\r\n";
}

/**
 * @details Извлекает логин и пароль, сопоставляет их с записями в БД. Если аутентификация успешна,
 * дополнительно проверяет роль пользователя (администратор или обычный пользователь) для возврата правильного токена.
 */
QString login(QStringList args, int socket_descriptor)
{
    Database* db = Database::getInstance();
    if (args.size() >= 3) {
        if (db->is_auth_ok(args[1], args[2], socket_descriptor)) {
            if (db->is_admin(socket_descriptor)) {
                return "log_success admin\r\n";
            }
            return "log_success user\r\n";
        }
    }
    return "log_fail\r\n";
}
/**
 * @details Проверяет, авторизован ли текущий сокет, и вызывает метод log_out в БД.
 * Разрывает логическую сессию пользователя без закрытия самого сетевого соединения.
 */
QString logout(QStringList args, int socket_descriptor)
{
    Database* db = Database::getInstance();
    if (db->log_out(socket_descriptor)) {
        return "logout_success\r\n";
    }
    return "logout_fail\r\n";
}

/**
 * @details Запрашивает из БД статистику по всем 5 типам задач именно для того пользователя,
 * который закреплен за текущим сокетом.
 */
QString get_current_stat(QStringList args, int socket_descriptor)
{
    Database* db = Database::getInstance();
    return db->get_current_stat(socket_descriptor);
}

/**
 * @details Администраторская команда. Возвращает сводную матрицу результатов
 * (до 15 пользователей), если у вызывающего сокета есть права администратора.
 */
QString get_all_stat(QStringList args, int socket_descriptor)
{
    Database* db = Database::getInstance();
    return db->get_all_stat(socket_descriptor);
}

/**
 * @details Проверяет права доступа и текущее состояние задач пользователя. Если задача выбранного типа
 * уже сгенерирована и активна, функция возвращает её payload. Если активной задачи нет,
 * генерирует новую через generate_task() и сохраняет её в БД перед отправкой клиенту.
 */
QString get_task(QStringList args, int socket_descriptor) {
    Database* db = Database::getInstance();
    if(args.size() < 2) {
        return "get_task_error\r\n";
    }
    if (!db->is_connected(socket_descriptor)) {
        return "not_authenticated\r\n";
    }
    int task_type = args[1].toInt();
    if (task_type < 1 || task_type > 5) {
        return "task_not_found\r\n";
    }
    CurrentTask current = db->get_current_task(socket_descriptor);
    if (current.is_valid() && current.type == task_type) {
        return QString("TASK %1 %2\r\n").arg(current.type).arg(current.payload);
    }
    CurrentTask new_task = generate_task(task_type);
    if (!new_task.is_valid()) {
        return "task_generation_error\r\n";
    }
    if (!db->save_current_task(socket_descriptor, new_task)) {
        return "task_save_error\r\n";
    }
    return QString("TASK %1 %2\r\n").arg(new_task.type).arg(new_task.payload);
}

/**
 * @details Получает сохраненную для данного сокета задачу, сравнивает ответ пользователя с правильным ответом.
 * Для нестроковых (математических) ответов производит сравнение вещественных чисел с эпсилон-точностью 1e-3.
 * Обновляет статистику баллов в БД и сбрасывает активную задачу.
 */
QString solve_task(QStringList args, int socket_descriptor) {
    Database* db = Database::getInstance();
    CurrentTask task = db->get_current_task(socket_descriptor);

    if (args.size() >= 3 && db->is_connected(socket_descriptor) && task.is_valid()) {
        int task_number = args[1].toInt();
        QString user_answer = args[2];

        if (task_number < 1 || task_number > 5 || task_number != task.type) {
            return "task_not_found\r\n";
        }

        bool is_correct = false;

        if (task_number == 4) {
            is_correct = (user_answer == task.answer);
        } else {
            bool ok1 = false, ok2 = false;
            double a = user_answer.toDouble(&ok1);
            double b = task.answer.toDouble(&ok2);
            if (ok1 && ok2) {
                is_correct = std::abs(a - b) < 1e-3;
            }
        }

        db->update_stat(task_number, socket_descriptor, is_correct);
        db->clear_current_task(socket_descriptor);
        return is_correct ? "answer_correct\r\n" : "answer_incorrect\r\n";
    }
    return "solve_task_error\r\n";
}

/**
 * @details Администраторская команда. Извлекает логин целевого пользователя из аргументов
 * и полностью удаляет его из таблицы БД, если сокет-отправитель валиден и имеет роль 'admin'.
 */
QString delete_user(QStringList args, int socket_descriptor){
    Database* db = Database::getInstance();
    QString login = args[1];

    if (db->delete_user(login, socket_descriptor)) {
        return "del_user_success\r\n";
    }
    return "del_user_error\r\n";
}

/**
 * @details Администраторская команда. Формирует сортированную по убыванию общего балла
 * таблицу из топ-10 пользователей системы. При отсутствии прав возвращает ошибку доступа.
 */
QString get_top10_stat(QStringList args, int socket_descriptor)
{
    Database* db = Database::getInstance();
    return db->get_top_10_stat(socket_descriptor);
}
