#include "tcpserver.h"

MyTcpServer::~MyTcpServer()
{
    for (auto socket : mSockets) {
        Database::getInstance()->log_out(mSockets.key(socket));
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
    Database::getInstance()->drop_all_connections();
}

void MyTcpServer::slotNewConnection(){
    while (mTcpServer->hasPendingConnections()) {
        QTcpSocket *mTcpSocket;
        mTcpSocket = mTcpServer->nextPendingConnection(); //добавить объявление: QTcpSocket *mTcpSocket...
        mTcpSocket->write("connected\r\n");
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
            mTcpSocket->write(res.toUtf8());
            res = "";
        }
        else
            res.append(array);
    }
    // if (res.toUtf8().toLower() == "exit\r\n") {
    //     mTcpSocket->write("Connection will be closed!\r\n");
    //     mTcpSocket->disconnectFromHost();
    // }
    qDebug() << "========================================";
    qDebug() << "Received from client:" << res;
    qDebug() << "Socket descriptor:" << mTcpSocket->socketDescriptor();

    QString response = mParser.parse(res, mTcpSocket->socketDescriptor());

    qDebug() << "Sending response:" << response;
    qDebug() << "========================================";

    mTcpSocket->write(response.toUtf8());

}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket *mTcpSocket = qobject_cast<QTcpSocket*>(sender());
    if (!mTcpSocket)
        return;

    qintptr socket_descriptor = mSockets.key(mTcpSocket);
    Database::getInstance()->log_out(socket_descriptor);
    mSockets.remove(socket_descriptor);
    mTcpSocket->close();
    mTcpSocket->deleteLater();
}
