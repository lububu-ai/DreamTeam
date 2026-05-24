#include "commandparser.h"

/**
 * @file commandparser.cpp
 * @brief Реализация класса CommandParser для диспетчеризации входящих команд.
 */

/**
 * @details Заполняет ассоциативный массив (карту) доступных серверных команд,
 * связывая их строковые имена с соответствующими указателями на функции-обработчики.
 */
CommandParser::CommandParser() {
    commands["REG"] = register_user;
    commands["LOG"] = login;
    commands["OUT"] = logout;
    commands["GST"] = get_current_stat;
    commands["AST"] = get_all_stat;
    commands["GET_TASK"] = get_task;
    commands["SOLVE"] = solve_task;
    commands["DEL_USER"] = delete_user;
    commands["GST10"] = get_top10_stat;
}

/**
 * @details Выполняет очистку строки от пробельных символов, разбивает её по пробелам
 * на имя команды и аргументы. Если команда найдена в списке зарегистрированных,
 * вызывает привязанный обработчик. В противном случае возвращает статус ошибки.
 */
QString CommandParser::parse(QString input_command, int socket_descriptor)
{
    input_command = input_command.trimmed();
    if (input_command.isEmpty())
        return "empty_command\r\n";

    QStringList list = input_command.split(' ', Qt::SkipEmptyParts);

    if (list.isEmpty())
        return "empty_command\r\n";

    auto iter = commands.find(list[0]);
    if (iter == commands.end()) {
        return "unknown_command\r\n";
    }

    return iter.value()(list, socket_descriptor);
}
