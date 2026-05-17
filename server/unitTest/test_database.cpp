#include "test_database.h"



void TestDatabase::initTestCase()
{
    Database::getInstance()->drop_all_connections();
}

void TestDatabase::cleanup()
{
    Database::getInstance()->delete_user("test_user");
}

void TestDatabase::reg_not_enough_arguments_error()
{
    CommandParser parser;
    QCOMPARE(parser.parse("REG",1),"reg_fail\r\n");
}

void TestDatabase::reg_success()
{
    CommandParser parser;
    QCOMPARE(parser.parse("REG test_user test@mail.com test_password",1), "reg_success\r\n");
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
    QCOMPARE(parser.parse("LOG test_user test_password",1), "log_success\r\n");
}


void TestDatabase::reg_user_exists_error()
{
    CommandParser parser;
    parser.parse("OUT",1);
    QCOMPARE(parser.parse("REG test_user test_password",1), "reg_fail\r\n");
}
