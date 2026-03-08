#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QString>
#include <QMap>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

#include "commandparser.h"

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
private:
    QTcpServer * mTcpServer;
    QMap<qintptr, QTcpSocket*> mSockets;
    CommandParser mParser;
    //int server_status;
};
#endif // TCPSERVER_H







