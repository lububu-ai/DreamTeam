#ifndef CLIENTFUNCS_H
#define CLIENTFUNCS_H
#include<QString>
#include <QStringList>
#include <QVector>

bool auth(QString log, QString pw, QString& role);
bool reg(QString log, QString email, QString pw, QString& role);
QString getTask(QString num);
QString getStats();
bool sendAnswer(QString num, QString answer);
void extractArgs(QString servAns, QVector <QString> &args);
QString getAllStats();
QString getTop10Stats();
bool delete_user(QString login);
QString getStatsTable(QString serverData);

#endif // CLIENTFUNCS_H
