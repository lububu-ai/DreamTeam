#ifndef TST_COMMANDPARSER_H
#define TST_COMMANDPARSER_H

#include <QObject>
#include <QtTest>
#include "../app/commandparser.h"

class TestCommandParser : public QObject
{
    Q_OBJECT

private slots:
    void empty_command();
    void unknown_command();
    // void reg_error();
    // void reg_success();
    // void log_error();
    // void log_success();
    // void logout_success();
    void get_task_success();
    void get_task_error();
};

#endif // TEST_COMMANDPARSER_H
