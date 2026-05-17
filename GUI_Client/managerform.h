#ifndef MANAGERFORM_H
#define MANAGERFORM_H

#include "authregform.h"
#include "mainform.h"

#include <QObject>

class ManagerForm:public QObject
{
    Q_OBJECT
public:
    ManagerForm();
private:
    AuthRegForm *w;
    MainForm *m;

public slots:
    void slot_on_auth_ok();


};

#endif // MANAGERFORM_H
