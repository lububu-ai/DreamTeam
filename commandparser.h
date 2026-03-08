#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <QString>
#include <QStringList>
#include <QMap>
#include <functional>

#include "commands.h"

class CommandParser
{
private:
    QMap<QString, std::function<QString(QStringList, int)>> commands;
public:
    CommandParser();
    QString parse(QString, int);
};

#endif // COMMANDPARSER_H
