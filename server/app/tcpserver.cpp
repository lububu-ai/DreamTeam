#include "tcpserver.h"

/**
 * @file tcpserver.cpp
 * @brief Реализация логики асинхронного TCP-сервера.
 */

/**
 * @details Деструктор проходит по всем сокетам в карте подключений, принудительно разрывает
 * сессию пользователя в базе данных (вызывает log_out) и безопасно удаляет объекты сокетов.
 * После этого закрывает сам сервер.
 */
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

/**
 * @details Конструктор связывает сигнал нового подключения с обработчиком slotNewConnection().
 * Запускает прослушивание порта 33333 на всех доступных сетевых интерфейсах.
 * При успешном старте или ошибке выводится сообщение в отладочный лог.
 * Также принудительно сбрасывает старые активные соединения в базе данных, оставшиеся от предыдущего сеанса.
 */
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

/**
 * @details Циклически забирает все ожидающие подключения из очереди QTcpServer.
 * Каждому новому клиенту отправляет текстовый маркер подключения "connected\r\n".
 * Подключает сигналы readyRead и disconnected к соответствующим внутренним слотам сервера.
 * Добавляет сокет во внутренний контейнер mSockets по его дескриптору.
 */
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

/**
 * @details Определяет, от какого именно сокета пришли данные (с помощью qobject_cast).
 * Считывает все доступные байты из потока сокета. Если встречает символ \x01, отправляет
 * накопленный буфер ответа обратно, иначе накапливает строку команды.
 * Полученная полная строка отправляется на обработку в CommandParser, результат которой записывается в сокет клиента.
 */
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

/**
 * @details Определяет дескриптор отключившегося сокета.
 * Информирует базу данных о закрытии сессии пользователя (log_out).
 * Удаляет сокет из карты активных подключений mSockets и помечает объект для автоматического безопасного удаления.
 */
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
