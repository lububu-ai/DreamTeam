#include <QCoreApplication>
#include <QtTest>

#include "test_commandparser.h"
#include "test_database.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    int status = 0;

    {
        TestCommandParser tc;
        status |= QTest::qExec(&tc, argc, argv);
    }

    {
        TestDatabase td;
        status |= QTest::qExec(&td, argc, argv);
    }

    return status;
}
