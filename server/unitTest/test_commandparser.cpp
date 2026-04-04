#include "test_commandparser.h"

void TestCommandParser::empty_command() {
    CommandParser parser;
    QCOMPARE(parser.parse("   ", 1), QString("empty_command\r\n"));
};
void TestCommandParser::unknown_command() {
    CommandParser parser;
    QCOMPARE(parser.parse("UNKNOWN_COMMAND", 1), QString("unknown_command\r\n"));
};
void TestCommandParser::get_task_success() {
    CommandParser parser;
    QString res = parser.parse("GET_TASK 1", 1);
    QVERIFY(res.startsWith("TASK 1 "));
};
void TestCommandParser::get_task_error() {
    CommandParser parser;
    QCOMPARE(parser.parse("UNKNOWN_COMMAND", 1), QString("unknown_command\r\n"));
};
