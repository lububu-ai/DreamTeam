#ifndef MANAGERFORM_H
#define MANAGERFORM_H

#include "authregform.h"
#include "mainform.h"
#include "adminform.h"

#include <QObject>

class ManagerForm:public QObject
{
    Q_OBJECT
public:
    ManagerForm();
private:
    AuthRegForm *w;
    MainForm *m;
    AdminForm *adminForm;

public slots:
    void slot_on_auth_ok(const QString& role);


};

#endif // MANAGERFORM_H
