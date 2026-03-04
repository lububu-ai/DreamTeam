#include "server_functions.h"
#include <map>

QString parsing(QString str) {
    int num = 0;
     // map с командами
    std::map<QString, int> dict = {{"exit\r\n", 1}, // закрытие соединения
                                   {"registration\r\n", 2}, {"reg\r\n", 2}, // регистрация
                                   {"authorization\r\n", 3}, {"auth\r\n", 3}, // авторизация
                                   {"unlog\r\n", 4}, {"un", 4}, // выход из аккаунта
                                   {"check\r\n", 5}, {"ch\r\n", 5}, // главная функция
                                   {"information", 6}, {"info", 6}}; // информация о возможностях программы
    if (dict.contains(str.toLower())) { // проверка на наличие команды
        num = dict[str.toLower()]; //
    }
    switch (num) {
    case 1: // закрытие соединения
        //exit_from_connection();
        return "Connection will be closed!\r\n";
        break;
    case 2: // регистрация
        //registration();
        return "Registration completed.\r\n";
        break;
    case 3: // авторизация
        //authorization();
        return "Authorization completed.\r\n";
        break;
    case 4: // выход из аккаунта
        //unlog();
        return "Unlogging completed!\r\n";
        break;
    case 5: // главная функция
        //check();
        return "Check\r\n";
        break;
    case 6: // информация о возможностях программы
        //exit_from_connection();
        return "Information:\r\nЗдесь что-то будет...\r\n";
    default: // неправильная команда
        return "Nothing happened\r\n";
        break;
    };
};
