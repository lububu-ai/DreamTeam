#include <QCoreApplication>
#include "tcpserver.h"

int main(int argc, char *argv[])
{
    srand(time(nullptr));
    QCoreApplication a(argc, argv);
    MyTcpServer myserv;
    return a.exec();
}
