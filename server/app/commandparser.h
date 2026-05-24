#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <QString>
#include <QStringList>
#include <QMap>
#include <functional>

#include "commands.h"

/**
 * @file commandparser.h
 * @brief Объявление класса CommandParser, отвечающего за маршрутизацию текстовых команд.
 */

/**
 * @class CommandParser
 * @brief Класс для разбора входящих сетевых команд и вызова соответствующих функций-обработчиков.
 * * Данный класс хранит отображение (сопоставление) текстовых строк команд
 * к их функциональным указателям на обработчики.
 */

class CommandParser
{
private:
    /**
     * @brief Карта зарегистрированных команд.
     * Ключ — имя команды (например, "REG", "LOG"),
     * значение — лямбда или функция-обработчик с сигнатурой `QString(QStringList, int)`.
     */
    QMap<QString, std::function<QString(QStringList, int)>> commands;
public:
    /**
     * @brief Конструктор по умолчанию.
     * Инициализирует карту доступных команд и привязывает их к функциям из commands.h.
     */
    CommandParser();
    /**
     * @brief Разбирает входящую строку команды и вызывает нужный обработчик.
     * @param input_command Полная строка команды, полученная от клиента.
     * @param socket_descriptor Дескриптор сокета клиента, отправившего команду.
     * @return QString Ответ сервера, готовый к отправке обратно клиенту.
     */
    QString parse(QString, int);
};

#endif // COMMANDPARSER_H
