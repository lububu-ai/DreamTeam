#include "singletonclient.h"

SingletonClient::SingletonClient(QObject * parent):QObject(parent){
    m_pTcpSocket = new QTcpSocket();
    m_pTcpSocket->connectToHost("127.0.0.1",33333);

    connect(m_pTcpSocket, SIGNAL(readyRead()), this, SLOT(slotServerRead()));
}

void SingletonClient::send_msg_to_server(QString query){
    m_pTcpSocket->write(query.toUtf8());
}

void SingletonClient::slotServerRead(){
    //qDebug() << "slot\n";
    QString msg = "";

    while(m_pTcpSocket->bytesAvailable() > 0){
        QByteArray array = m_pTcpSocket->readAll();
        msg.append(array);
    }

    qDebug() << msg;
    emit message_from_server(msg);
}



SingletonClient * SingletonClient::p_instance;
SingletonClientDestroyer SingletonClient::destroyer;
