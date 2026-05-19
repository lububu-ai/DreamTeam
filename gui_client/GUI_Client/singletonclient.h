#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H

#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QObject>
#include <QDebug>

class SingletonClient;

class SingletonClientDestroyer {
private:
    SingletonClient * p_instance;
public:
    ~SingletonClientDestroyer() {delete p_instance;}
    void initialize(SingletonClient * p){p_instance = p;}
};

class SingletonClient: public QObject{
    Q_OBJECT
private:
    static SingletonClient *p_instance;
    static SingletonClientDestroyer destroyer;
    QTcpSocket* m_pTcpSocket;
    quint16 m_nNextBlockSize;
protected:
    SingletonClient(QObject *parent = nullptr);
    SingletonClient(const SingletonClient&) = delete;
    SingletonClient& operator = (SingletonClient &) = delete;
    ~SingletonClient(){
        //m_pTcpSocket->close();
    }

    friend class SingletonClientDestroyer;
public:
    static SingletonClient* getInstance(){
        if(!p_instance){
            p_instance = new SingletonClient();
            destroyer.initialize(p_instance);
        }

        return p_instance;
    }

    QString send_msg_to_server(QString query);
signals:
    void message_from_server(QString msg);
private slots:
    //void slotServerRead();
};

#endif // SINGLETONCLIENT_H
