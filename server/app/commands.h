#include <QString>
#include <QStringList>
#include <QDebug>
#include <cmath>

#include "database.h"
#include "tasks.h"

/**
 * @file commands.h
 * @brief Объявление функций-обработчиков для различных команд протокола.
 */

/**
 * @brief Регистрация нового пользователя.
 * @param args Список аргументов команды: [0] - "REG", [1] - login, [2] - email, [3] - password.
 * @param socket_descriptor Дескриптор сокета текущего подключения.
 * @return QString "reg_success user\r\n" или "reg_fail\r\n".
 */
QString register_user(QStringList, int);
/**
 * @brief Аутентификация (вход) пользователя.
 * @param args Список аргументов команды: [0] - "LOG", [1] - login, [2] - password.
 * @param socket_descriptor Дескриптор сокета текущего подключения.
 * @return QString Статус входа: для админа, пользователя, либо ошибка.
 */
QString login(QStringList, int);
/**
 * @brief Выход пользователя из системы (разрыв сессии).
 * @param args Список аргументов команды.
 * @param socket_descriptor Дескриптор сокета текущего подключения.
 * @return QString "logout_success\r\n" или "logout_fail\r\n".
 */
QString logout(QStringList, int);
/**
 * @brief Получение статистики текущего (авторизованного) пользователя.
 * @param args Список аргументов команды.
 * @param socket_descriptor Дескриптор сокета текущего подключения.
 * @return QString Строка со статистикой по 5 задачам, разделенная "||".
 */
QString get_current_stat(QStringList, int);
/**
 * @brief Получение статистики всех пользователей (доступно только админу).
 * @param args Список аргументов команды.
 * @param socket_descriptor Дескриптор сокета текущего подключения.
 * @return QString Сводный список пользователей и их очков или сообщение об ошибке доступа.
 */
QString get_all_stat(QStringList, int);

/**
 * @brief Получение математической или логической задачи.
 * * Если у пользователя уже есть активная задача выбранного типа, возвращается она.
 * В противном случае генерируется и сохраняется новая.
 * * @param args Список аргументов: [1] - тип задачи (от 1 до 5).
 * @param socket_descriptor Дескриптор сокета текущего подключения.
 * @return QString Данные задачи (TASK тип payload) или текст ошибки.
 */
QString get_task(QStringList, int);
/**
 * @brief Проверка решения задачи, отправленного пользователем.
 * @param args Список аргументов: [1] - номер задачи, [2] - ответ пользователя.
 * @param socket_descriptor Дескриптор сокета текущего подключения.
 * @return QString "answer_correct\r\n" или "answer_incorrect\r\n".
 */
QString solve_task(QStringList, int);
/**
 * @brief Генератор случайных задач по типам.
 * * Поддерживает 5 различных математических/алгоритмических задач:
 * - 1: Формула Симпсона (Мусихин)
 * - 2: Метод хорд / Линейные функции (Филатов)
 * - 3: Дихотомия / деление отрезка (Шилова)
 * - 4: Поиск листьев в дереве обходом в глубину (Семенец)
 * - 5: Вычисление аналитической функции с логарифмом и корнем (Рыбакин)
 * @param task_type Идентификатор типа задачи (от 1 до 5).
 * @return CurrentTask Структура с типом, payload-строкой параметров и строкой правильного ответа.
 */
CurrentTask generate_task(int);
/**
 * @brief Удаление пользователя из базы данных (доступно только админу).
 * @param args Список аргументов: [1] - login удаляемого пользователя.
 * @param socket_descriptor Дескриптор сокета текущего подключения.
 * @return QString "del_user_success\r\n" или "del_user_error\r\n".
 */
QString delete_user(QStringList, int);
/**
 * @brief Получение топ-10 пользователей по сумме баллов (доступно только админу).
 * @param args Список аргументов команды.
 * @param socket_descriptor Дескриптор сокета текущего подключения.
 * @return QString Список топ-10 или сообщение об ошибке доступа.
 */
QString get_top10_stat(QStringList, int);
