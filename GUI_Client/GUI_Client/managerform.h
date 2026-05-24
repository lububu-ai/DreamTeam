#ifndef MANAGERFORM_H
#define MANAGERFORM_H

#include "authregform.h"
#include "mainform.h"
#include "adminform.h"

#include <QObject>

/**
 * @file managerform.h
 * @brief Класс-контроллер для переключения между окнами приложения (архитектура на базе сигналов и слотов).
 */

/**
 * @class ManagerForm
 * @brief Главный менеджер графических окон (форм) приложения.
 * * Данный класс не имеет собственного графического представления. Он распределяет
 * оперативную память под формы `AuthRegForm`, `MainForm` и `AdminForm` и на основе сигналов
 * успешного входа показывает нужное окно, скрывая предыдущее.
 */
class ManagerForm:public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Конструктор менеджера форм.
     * * Создает стартовое окно `AuthRegForm`, подписывается на его сигналы и выводит форму на экран.
     */
    ManagerForm();
private:
    AuthRegForm *w; ///< Указатель на виджет авторизации/регистрации.
    MainForm *m; ///< Указатель на личный кабинет пользователя.
    AdminForm *adminForm; ///< Указатель на панель администратора.

public slots:
    /**
     * @brief Слот-обработчик сигнала успешной аутентификации на сервере.
     * * Скрывает стартовое окно авторизации и открывает `MainForm` для роли «user» или `AdminForm` для роли «admin».
     * @param role Строковая роль вошедшего аккаунта («user» / «admin»).
     */
    void slot_on_auth_ok(const QString& role);


};

#endif // MANAGERFORM_H
