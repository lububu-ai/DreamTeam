#include <QtTest/QtTest>
#include <QCoreApplication>
#include "test_clientfuncs.h"
#include "test_singletonclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    int status = 0;

    TestClientFuncs testClientFuncs;
    status |= QTest::qExec(&testClientFuncs, argc, argv);

    TestSingletonClient testSingletonClient;
    status |= QTest::qExec(&testSingletonClient, argc, argv);

    return status;
}
