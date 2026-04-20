#include "clientfuncs.h"
#include "singletonclient.h"

bool auth(QString log, QString pw){
    //if(log == "222" && pw == "222") return true;
    QString msg = "LOG " + log + " " + pw + "\r\n";
    QString servAns = SingletonClient::getInstance()->send_msg_to_server(msg);
    qDebug() << servAns;
    if(servAns == QString::fromStdString("log_success\r\n")) return true;
    return false;
}

bool reg(QString log, QString email, QString pw){
    QString msg = "REG " + log + " " + email + " " + pw + "\r\n";
    QString servAns = SingletonClient::getInstance()->send_msg_to_server(msg);
    qDebug() << servAns;
    if(servAns == QString::fromStdString("reg_success\r\n")) return true;
    return false;
}

QString getTask(QString num){
    QString msg = "GET_TASK " + num + "\r\n";
    QString servAns = SingletonClient::getInstance()->send_msg_to_server(msg);
    qDebug() << servAns;
    return servAns;
}

bool sendAnswer(QString num, QString answer){
    QString msg = "SOLVE " + num + " " + answer + "\r\n";
    QString servAns = SingletonClient::getInstance()->send_msg_to_server(msg);
    qDebug() << servAns;

    if(servAns == QString::fromStdString("answer_correct\r\n")) return true;
    return false;
}

QString getStats(){
    QString servAns = SingletonClient::getInstance()
                          ->send_msg_to_server(QString::fromStdString("GST\r\n"));
    qDebug() << servAns;
    return servAns;
}

void extractArgs(QString servAns, QVector <QString> &args){
    servAns = servAns.trimmed();

    QStringList medium_rare = servAns.split(' ', Qt::SkipEmptyParts);
    QStringList medium_well = medium_rare[2].split(';', Qt::SkipEmptyParts);
    //qDebug() << medium_well;

    for(int i = 0; i < args.size();++i){
        args[i] = medium_well[i];
    }
}

