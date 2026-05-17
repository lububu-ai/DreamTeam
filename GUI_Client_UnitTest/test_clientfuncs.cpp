#include "test_clientfuncs.h"
#include "clientfuncs.h"

class MockSingletonClient {
public:
    static QString mockResponse;
    static QString lastSentMessage;
    static int sendCount;

    static QString send_msg_to_server(const QString& msg) {
        lastSentMessage = msg;
        sendCount++;
        return mockResponse;
    }

    static void reset() {
        mockResponse = "";
        lastSentMessage = "";
        sendCount = 0;
    }
};

QString MockSingletonClient::mockResponse = "";
QString MockSingletonClient::lastSentMessage = "";
int MockSingletonClient::sendCount = 0;

namespace TestWrappers {
bool testAuth(const QString& log, const QString& pw) {
    QString msg = "LOG " + log + " " + pw + "\r\n";
    QString servAns = MockSingletonClient::send_msg_to_server(msg);
    return servAns == "log_success\r\n";
}

QString testGetTask(const QString& num) {
    QString msg = "GET_TASK " + num + "\r\n";
    return MockSingletonClient::send_msg_to_server(msg);
}

bool testSendAnswer(const QString& num, const QString& answer) {
    QString msg = "SOLVE " + num + " " + answer + "\r\n";
    QString servAns = MockSingletonClient::send_msg_to_server(msg);
    return servAns == "answer_correct\r\n";
}
}

void TestClientFuncs::testExtractArgsNormal()
{
    QString response = "GET_TASK 1 0.1;1.0;2.0;3.0\n";
    QVector<QString> expected = {"0.1", "1.0", "2.0", "3.0"};
    QVector<QString> actual(4);

    extractArgs(response, actual);

    for(int i = 0; i < expected.size(); ++i) {
        QCOMPARE(actual[i], expected[i]);
    }
}

void TestClientFuncs::testAuthMessageFormat()
{
    MockSingletonClient::reset();
    MockSingletonClient::mockResponse = "log_success\r\n";

    TestWrappers::testAuth("user123", "pass456");

    QString expected = "LOG user123 pass456\r\n";
    QCOMPARE(MockSingletonClient::lastSentMessage, expected);
}

void TestClientFuncs::testRegMessageFormat()
{
    MockSingletonClient::reset();
    MockSingletonClient::mockResponse = "reg_success\r\n";

    QString msg = "REG newuser email@test.com pass123\r\n";
    MockSingletonClient::send_msg_to_server(msg);

    QString expected = "REG newuser email@test.com pass123\r\n";
    QCOMPARE(MockSingletonClient::lastSentMessage, expected);
}

void TestClientFuncs::testGetTaskMessageFormat()
{
    MockSingletonClient::reset();
    TestWrappers::testGetTask("2");

    QString expected = "GET_TASK 2\r\n";
    QCOMPARE(MockSingletonClient::lastSentMessage, expected);
}

void TestClientFuncs::testSendAnswerMessageFormat()
{
    MockSingletonClient::reset();
    TestWrappers::testSendAnswer("3", "2.71828");

    QString expected = "SOLVE 3 2.71828\r\n";
    QCOMPARE(MockSingletonClient::lastSentMessage, expected);
}

void TestClientFuncs::testAuthSuccess()
{
    MockSingletonClient::reset();
    MockSingletonClient::mockResponse = "log_success\r\n";

    bool result = TestWrappers::testAuth("user", "pass");
    QVERIFY(result);
}

void TestClientFuncs::testAuthFail()
{
    MockSingletonClient::reset();
    MockSingletonClient::mockResponse = "log_failed\r\n";

    bool result = TestWrappers::testAuth("user", "wrong");
    QVERIFY(!result);
}

void TestClientFuncs::testSendAnswerCorrect()
{
    MockSingletonClient::reset();
    MockSingletonClient::mockResponse = "answer_correct\r\n";

    bool result = TestWrappers::testSendAnswer("1", "2.5");
    QVERIFY(result);
}

void TestClientFuncs::testSendAnswerIncorrect()
{
    MockSingletonClient::reset();
    MockSingletonClient::mockResponse = "answer_incorrect\r\n";

    bool result = TestWrappers::testSendAnswer("1", "wrong");
    QVERIFY(!result);
}
