#include "managerform.h"
#include "singletonclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ManagerForm s;

    QString conec = SingletonClient::getInstance()->send_msg_to_server(QString::fromStdString(""));

    return a.exec();
}
