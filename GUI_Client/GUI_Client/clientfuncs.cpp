#include "clientfuncs.h"
#include "singletonclient.h"
/**
 * @file clientfuncs.cpp
 * @brief Реализация функций сетевого взаимодействия, валидации и форматирования данных для клиента.
 */

/**
 * @brief Авторизация пользователя в системе.
 * * Формирует строку запроса вида "LOG login password\r\n", отправляет её на сервер
 * и анализирует ответ для определения роли пользователя.
 * @param log Логин пользователя.
 * @param pw Пароль пользователя.
 * @param[out] role Ссылка для сохранения роли ("admin" или "user").
 * @return true, если авторизация успешна (сервер вернул "log_success"), иначе false.
 */
bool auth(QString log, QString pw, QString& role){
    QString msg = "LOG " + log + " " + pw + "\r\n";
    QString servAns = SingletonClient::getInstance()->send_msg_to_server(msg);

    if(servAns.startsWith("log_success")) {
        qInfo() << "Success log_success";
        if (servAns.contains("admin")) {
            role = "admin";
        }
        else {
            role = "user";
        }
        return true;
    }
    return false;
}

/**
 * @brief Регистрация нового пользователя в системе.
 * * Отправляет запрос "REG login email password\r\n". При успешной регистрации
 * пользователю автоматически присваивается стандартная роль "user".
 * @param log Логин пользователя.
 * @param email Электронная почта.
 * @param pw Пароль пользователя.
 * @param[out] role Ссылка для записи роли по умолчанию.
 * @return true, если регистрация прошла успешно, иначе false.
 */
bool reg(QString log, QString email, QString pw, QString& role){
    QString msg = "REG " + log + " " + email + " " + pw + "\r\n";
    QString servAns = SingletonClient::getInstance()->send_msg_to_server(msg);

    if(servAns.startsWith("reg_success")) {
        role = "user";
        return true;
    }
    return false;
}

/**
 * @brief Запрос payload-строки параметров математической задачи у сервера.
 * @param num Строковый номер типа задачи (1-5).
 * @return QString Сырой ответ сервера, содержащий сгенерированные параметры.
 */
QString getTask(QString num){
    QString msg = "GET_TASK " + num + "\r\n";
    QString servAns = SingletonClient::getInstance()->send_msg_to_server(msg);
    qDebug() << servAns;
    return servAns;
}

/**
 * @brief Получение персональной статистики текущего авторизованного пользователя.
 * @return QString Строка со статистикой по выполненным задачам.
 */
bool sendAnswer(QString num, QString answer){
    QString msg = "SOLVE " + num + " " + answer + "\r\n";
    QString servAns = SingletonClient::getInstance()->send_msg_to_server(msg);
    qDebug() << servAns;

    if(servAns == QString::fromStdString("answer_correct\r\n")) return true;
    return false;
}

/**
 * @brief Отправка ответа на задачу для проверки на стороне сервера.
 * @param num Номер проверяемой задачи.
 * @param answer Строка с ответом, введённым пользователем.
 * @return true, если сервер подтвердил правильность ответа ("answer_correct"), иначе false.
 */
QString getStats(){
    QString servAns = SingletonClient::getInstance()
                          ->send_msg_to_server(QString::fromStdString("GST\r\n"));
    qDebug() << servAns;
    return servAns;
}

/**
 * @brief Вспомогательная функция для парсинга аргументов из ответа сервера.
 * * Разбивает строку по разделителю "||" и удаляет символы переноса строки.
 * @param servAns Ответ, пришедший от сервера.
 * @param[out] args Вектор для сохранения извлеченных параметров.
 */
void extractArgs(QString servAns, QVector <QString> &args){
    servAns = servAns.trimmed();

    QStringList medium_rare = servAns.split(' ', Qt::SkipEmptyParts);
    QStringList medium_well = medium_rare[2].split(';', Qt::SkipEmptyParts);
    //qDebug() << medium_well;

    for(int i = 0; i < args.size();++i){
        args[i] = medium_well[i];
    }
}

/**
 * @brief Запрос статистики по всем пользователям (только для администратора).
 * @return QString Сводный текстовый массив данных всех учетных записей.
 */
QString getAllStats(){
    QString servAns = SingletonClient::getInstance()
    ->send_msg_to_server(QString::fromStdString("AST\r\n"));
    qDebug() << servAns;
    return servAns;
}

/**
 * @brief Запрос топ-10 пользователей по сумме набранных баллов (только для администратора).
 * @return QString Текстовая таблица лидеров от сервера.
 */
QString getTop10Stats(){
    QString servAns = SingletonClient::getInstance()
    ->send_msg_to_server(QString::fromStdString("GST10\r\n"));
    qDebug() << servAns;
    return servAns;
}

/**
 * @brief Удаление пользователя из базы данных по его логину (только для администратора).
 * @param login Логин удаляемого пользователя.
 * @return true, если удаление прошло успешно на сервере, иначе false.
 */
bool delete_user(QString login){
    QString msg = "DEL_USER " + login + "\r\n";
    QString servAns = SingletonClient::getInstance()->send_msg_to_server(msg);
    qDebug() << "Server answer:" << servAns;

    if(servAns.startsWith("del_user_success")) {
        return true;
    }
    return false;
}

/**
 * @brief Форматирование сырых данных от сервера в псевдографическую таблицу.
 * * Вычисляет оптимальную ширину столбцов на основе входящих данных и
 * строит текстовую таблицу с выравниванием по левому краю.
 * @param serverData Ответ сервера, содержащий строки, разделенные "\r\n", и столбцы, разделенные "||".
 * @return QString Готовая для вывода в интерфейс моноширинная текстовая таблица.
 */
QString getStatsTable(QString serverData) {
    QStringList lines = serverData.split("\r\n", Qt::SkipEmptyParts);

    if (lines.isEmpty()) {
        return "Нет данных для отображения";
    }

    QVector<QStringList> usersData;
    int maxLoginLen = 6;
    int maxTaskLen[5] = {4, 4, 4, 4, 4};
    int maxTotalLen = 5;

    for (const QString& line : lines) {
        QStringList parts = line.split("||");
        if (parts.size() >= 7) {
            usersData.append(parts);

            maxLoginLen = qMax(maxLoginLen, parts[0].length());

            for (int i = 0; i < 5; i++) {
                maxTaskLen[i] = qMax(maxTaskLen[i], parts[i + 1].length());
            }
            maxTotalLen = qMax(maxTotalLen, parts[6].length());
        }
    }

    maxLoginLen += 2;
    for (int i = 0; i < 5; i++) {
        maxTaskLen[i] += 2;
    }
    maxTotalLen += 2;

    QString result;

    auto addSeparator = [&]() {
        result += "+";
        result += QString("-").repeated(maxLoginLen) + "+";
        for (int i = 0; i < 5; i++) {
            result += QString("-").repeated(maxTaskLen[i]) + "+";
        }
        result += QString("-").repeated(maxTotalLen) + "+\r\n";
    };

    addSeparator();

    result += "|";
    result += QString("Логин").leftJustified(maxLoginLen) + "|";
    result += QString("T1").leftJustified(maxTaskLen[0]) + "|";
    result += QString("T2").leftJustified(maxTaskLen[1]) + "|";
    result += QString("T3").leftJustified(maxTaskLen[2]) + "|";
    result += QString("T4").leftJustified(maxTaskLen[3]) + "|";
    result += QString("T5").leftJustified(maxTaskLen[4]) + "|";
    result += QString("Итого").leftJustified(maxTotalLen) + "|\r\n";

    addSeparator();

    for (const auto& parts : usersData) {
        auto formatValue = [](const QString& val) -> QString {
            int num = val.toInt();
            if (num > 0) return QString("+%1").arg(num);
            return val;
        };

        result += "|";
        result += parts[0].leftJustified(maxLoginLen) + "|";
        result += formatValue(parts[1]).leftJustified(maxTaskLen[0]) + "|";
        result += formatValue(parts[2]).leftJustified(maxTaskLen[1]) + "|";
        result += formatValue(parts[3]).leftJustified(maxTaskLen[2]) + "|";
        result += formatValue(parts[4]).leftJustified(maxTaskLen[3]) + "|";
        result += formatValue(parts[5]).leftJustified(maxTaskLen[4]) + "|";

        QString totalStr = parts[6];
        int total = totalStr.toInt();
        if (total > 0) totalStr = "+" + totalStr;

        result += totalStr.leftJustified(maxTotalLen) + "|\r\n";
    }
    addSeparator();

    return result;
}

