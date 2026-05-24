#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H

#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QObject>
#include <QDebug>

class SingletonClient;
/**
 * @file singletonclient.h
 * @brief Объявление Singleton-класса для сетевого взаимодействия с TCP-сервером.
 */

/**
 * @class SingletonClientDestroyer
 * @brief Класс-разрушитель, отвечающий за корректное освобождение памяти Singleton-клиента.
 */
class SingletonClientDestroyer {
private:
    SingletonClient * p_instance; ///< Указатель на единственный экземпляр SingletonClient.
public:
    /**
     * @brief Деструктор, удаляющий объект клиента при завершении работы программы.
     */
    ~SingletonClientDestroyer() {delete p_instance;}
    /**
     * @brief Передача указателя на созданный экземпляр клиента.
     * @param p Указатель на SingletonClient.
     */
    void initialize(SingletonClient * p){p_instance = p;}
};

/**
 * @class SingletonClient
 * @brief Класс синглтона для отправки запросов на сервер через QTcpSocket.
 * * Гарантирует наличие единой точки отправки сообщений и постоянного сетевого соединения
 * на протяжении всей работы клиентской сессии.
 */
class SingletonClient: public QObject{
    Q_OBJECT
private:
    static SingletonClient *p_instance; ///< Статический указатель на единственный экземпляр класса.
    static SingletonClientDestroyer destroyer; ///< Статический объект-разрушитель.
    QTcpSocket* m_pTcpSocket; ///< Указатель на сокет Qt, используемый для работы с сетью.
    quint16 m_nNextBlockSize; ///< Размер следующего блока данных (резерв под пакетную передачу).
protected:
    /**
     * @brief Закрытый конструктор (реализация паттерна Singleton).
     */
    SingletonClient(QObject *parent = nullptr);
    SingletonClient(const SingletonClient&) = delete;
    SingletonClient& operator = (SingletonClient &) = delete;
    /**
     * @brief Закрытый деструктор.
     */
    ~SingletonClient(){
        //m_pTcpSocket->close();
    }

    friend class SingletonClientDestroyer;
public:
    /**
     * @brief Получение или создание единственного экземпляра SingletonClient.
     * @return Указатель на экземпляр SingletonClient.
     */
    static SingletonClient* getInstance(){
        if(!p_instance){
            p_instance = new SingletonClient();
            destroyer.initialize(p_instance);
        }

        return p_instance;
    }
    /**
     * @brief Синхронная/блокирующая отправка текстового запроса на сервер и ожидание ответа.
     * @param query Текстовая команда протокола.
     * @return QString Ответная строка от сервера.
     */
    QString send_msg_to_server(QString query);
signals:
    /**
     * @brief Сигнал, информирующий о получении новых асинхронных данных от сервера.
     * @param msg Строка с текстом сообщения.
     */
    void message_from_server(QString msg);
private slots:
    //void slotServerRead();
};

#endif // SINGLETONCLIENT_H
