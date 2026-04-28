#ifndef TEST_DATABASE_H
#define TEST_DATABASE_H

#include <QObject>
#include <QtTest>
#include "../app/commandparser.h"
#include "../app/database.h"

class TestDatabase : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void reg_not_enough_arguments_error();
    void reg_success();
    void logout_success();
    void log_error();
    void log_success();
    void reg_user_exists_error();
};

#endif // TEST_DATABASE_H
