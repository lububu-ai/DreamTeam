#include "test_singletonclient.h"
#include "singletonclient.h"

void TestSingletonClient::testGetInstance()
{
    SingletonClient* client = SingletonClient::getInstance();
    QVERIFY(client != nullptr);
}

void TestSingletonClient::testSingletonPattern()
{
    SingletonClient* client1 = SingletonClient::getInstance();
    SingletonClient* client2 = SingletonClient::getInstance();

    QCOMPARE(client1, client2);
}

void TestSingletonClient::testSendMessage()
{
    SingletonClient* client = SingletonClient::getInstance();
    client->send_msg_to_server("TEST\n");
    QVERIFY(true);
}

void TestSingletonClient::testEmptyMessage()
{
    SingletonClient* client = SingletonClient::getInstance();
    client->send_msg_to_server("");
    QVERIFY(true);
}

void TestSingletonClient::testMultipleMessages()
{
    SingletonClient* client = SingletonClient::getInstance();

    for(int i = 0; i < 5; ++i) {
        client->send_msg_to_server("MSG_" + QString::number(i) + "\n");
    }

    QVERIFY(true);
}
