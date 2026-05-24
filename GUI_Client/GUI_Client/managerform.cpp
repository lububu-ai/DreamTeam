#include "managerform.h"
/**
 * @file managerform.cpp
 * @brief Реализация класса-контроллера для навигации между экранами приложения.
 */

/**
 * @brief Конструктор контроллера ManagerForm.
 * * Создает форму `AuthRegForm`, связывает её сигнал auth_ok с собственным слотом
 * переключения окон и отображает её пользователю.
 */
ManagerForm::ManagerForm() {
    w = new AuthRegForm();
    w->show();
    connect(w, &AuthRegForm::auth_ok, this, &ManagerForm::slot_on_auth_ok);
}

/**
 * @brief Слот динамического переключения окон на основании роли вошедшего пользователя.
 * @param role Название роли ("admin" или любая другая роль пользователя).
 */
void ManagerForm::slot_on_auth_ok(const QString& role){
    qDebug() << role;
    if (role == "admin") {
        adminForm = new AdminForm();
        adminForm->show();
    }
    else {
        m = new MainForm();
        m->show();
    }

}


