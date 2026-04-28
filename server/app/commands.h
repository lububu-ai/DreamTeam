#include <QString>
#include <QStringList>
#include <QDebug>
#include <cmath>

#include "database.h"
#include "tasks.h"

QString register_user(QStringList, int);
QString login(QStringList, int);
QString logout(QStringList, int);
QString get_current_stat(QStringList, int);
QString get_all_stat(QStringList, int);

QString get_task(QStringList, int);
QString solve_task(QStringList, int);
CurrentTask generate_task(int);
