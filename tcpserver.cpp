#include "tcpserver.h"
#include "server_functions.h"

MyTcpServer::~MyTcpServer()
{
    for (auto socket : mSockets) {
        socket->close();
        socket->deleteLater();
    }
    mSockets.clear();
    mTcpServer->close();
}

MyTcpServer::MyTcpServer(QObject *parent): QObject(parent),
    mTcpServer(new QTcpServer(this))
{
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 33333)) {
        qDebug() << "Server is not started";
    } else {
        qDebug() << "Server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    while (mTcpServer->hasPendingConnections()) {
        QTcpSocket *mTcpSocket;
        mTcpSocket = mTcpServer->nextPendingConnection(); //добавить объявление: QTcpSocket *mTcpSocket...
        mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
        mSockets[mTcpSocket->socketDescriptor()] = mTcpSocket;
        //+добавить: mSockets[mTcpSocket->socketDescriptior] = mTcpSocket
    }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket *mTcpSocket = qobject_cast<QTcpSocket*>(sender());
    if (!mTcpSocket)
        return;
    QString res = "";
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array = mTcpSocket->readAll();
        qDebug()<<array<<"\n";
        if(array=="\x01")
        {
            mTcpSocket->write(parsing(res).toUtf8());
            res = "";
        }
        else
            res.append(array);
    }
    //if (res.toUtf8().toLower() == "exit\r\n") {
    //    mTcpSocket->write("Connection will be closed!\r\n");
    //    mTcpSocket->disconnectFromHost();
    //}
    mTcpSocket->write(parsing(res).toUtf8()); //parsing - обработчик входящих команд

}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket *mTcpSocket = qobject_cast<QTcpSocket*>(sender());
    mSockets.remove(mTcpSocket->socketDescriptor());
    mTcpSocket->close();
    mTcpSocket->deleteLater();
}
