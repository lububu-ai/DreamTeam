#include "managerform.h"

ManagerForm::ManagerForm() {
    w = new AuthRegForm();
    w->show();
    connect(w, &AuthRegForm::auth_ok, this, &ManagerForm::slot_on_auth_ok);
}

void ManagerForm::slot_on_auth_ok(){
    m = new MainForm();
    m->show();
}
