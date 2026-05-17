#ifndef CLIENTFUNCS_H
#define CLIENTFUNCS_H
#include<QString>
#include <QStringList>

bool auth(QString log, QString pw);
bool reg(QString log, QString email, QString pw);
QString getTask(QString num);
QString getStats();
bool sendAnswer(QString num, QString answer);
void extractArgs(QString servAns, QVector <QString> &args);

#endif // CLIENTFUNCS_H
