#include "test_database.h"



void TestDatabase::initTestCase()
{
    Database::getInstance()->drop_all_connections();
}

void TestDatabase::cleanup()
{
    Database::getInstance()->delete_user_test("test_user");
}

void TestDatabase::reg_not_enough_arguments_error()
{
    CommandParser parser;
    QCOMPARE(parser.parse("REG",1),"reg_fail\r\n");
}

void TestDatabase::reg_success()
{
    CommandParser parser;
    QString res = parser.parse("REG test_user test@mail.com test_password", 1);
    QVERIFY(res.startsWith("reg_success"));
}

void TestDatabase::logout_success()
{
    CommandParser parser;
    QCOMPARE(parser.parse("OUT",1), "logout_success\r\n");
}


void TestDatabase::log_error()
{
    CommandParser parser;
    QCOMPARE(parser.parse("LOG NEW_LOGIN NEW_PASSWORD",1), "log_fail\r\n");
}

void TestDatabase::log_success()
{
    CommandParser parser;
    parser.parse("REG test_user test@mail.com test_password",1), "reg_success\r\n";
    parser.parse("OUT",1);
    QString res = parser.parse("LOG test_user test_password", 1);
    QVERIFY(res.startsWith("log_success"));
}


void TestDatabase::reg_user_exists_error()
{
    CommandParser parser;
    parser.parse("OUT",1);
    QCOMPARE(parser.parse("REG test_user test_password",1), "reg_fail\r\n");
}
