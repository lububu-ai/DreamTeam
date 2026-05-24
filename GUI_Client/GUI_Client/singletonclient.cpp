#include "singletonclient.h"

/**
 * @file singletonclient.cpp
 * @brief Реализация Singleton-класса для отправки сообщений и получения ответов от TCP-сервера.
 */

/**
 * @brief Конструктор класса. Инициализирует сокет и подключается к серверу.
 * @param parent Родительский QObject.
 */
SingletonClient::SingletonClient(QObject * parent):QObject(parent){
    m_pTcpSocket = new QTcpSocket();
    m_pTcpSocket->connectToHost("127.0.0.1",33333);

    //connect(m_pTcpSocket, SIGNAL(readyRead()), this, SLOT(slotServerRead()));
}

/**
 * @brief Синхронный метод отправки сообщения на сервер с ожиданием ответа.
 * * Записывает данные в сокет, блокирует поток до появления ответа (таймаут 5 секунд)
 * и вычитывает все доступные байты.
 * @param query Строка запроса к серверу.
 * @return QString Текстовый ответ сервера.
 */
QString SingletonClient::send_msg_to_server(QString query){
    m_pTcpSocket->write(query.toUtf8());
    m_pTcpSocket->waitForReadyRead(5000);

    //qDebug()<<"slot\n";
    QString msg = "";

    while(m_pTcpSocket->bytesAvailable() > 0){
        QByteArray array = m_pTcpSocket->readAll();
        msg.append(array);
    }

    return msg;
}

/*void SingletonClient::slotServerRead(){
    //qDebug() << "slot\n";
    QString msg = "";

    while(m_pTcpSocket->bytesAvailable() > 0){
        QByteArray array = m_pTcpSocket->readAll();
        msg.append(array);
    }

    qDebug() << msg;
    emit message_from_server(msg);
}*/



SingletonClient * SingletonClient::p_instance;
SingletonClientDestroyer SingletonClient::destroyer;
