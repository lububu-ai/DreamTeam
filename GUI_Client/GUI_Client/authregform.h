#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QWidget>
#include <QMessageBox>
#include "clientfuncs.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class AuthRegForm;
}
QT_END_NAMESPACE

/**
 * @file authregform.h
 * @brief Заголовочный файл окна авторизации и регистрации.
 */

/**
 * @class AuthRegForm
 * @brief Класс формы интерфейса, отвечающий за ввод учетных данных пользователя.
 * * Позволяет переключаться между экранами входа и создания новой учетной записи,
 * валидирует поля ввода и передает их сетевым функциям.
 */
class AuthRegForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор формы авторизации.
     * @param parent Указатель на родительский виджет.
     */
    AuthRegForm(QWidget *parent = nullptr);
    /**
     * @brief Деструктор, уничтожающий элементы графического интерфейса UI.
     */
    ~AuthRegForm();

private slots:
    /**
     * @brief Слот нажатия кнопки «Войти». Вызывает логику проверки логина и пароля.
     */
    void on_pushButtonAuth_clicked();
    /**
     * @brief Слот переключения интерфейса в режим регистрации нового аккаунта.
     */
    void on_pushButtonChangeToREG_clicked();
    /**
     * @brief Слот возврата интерфейса в режим авторизации (входа).
     */
    void on_pushButtonChangeToAUTH_clicked();
    /**
     * @brief Слот нажатия кнопки «Зарегистрироваться». Отправляет данные на сервер для добавления в БД.
     */
    void on_pushButtonReg_clicked();
signals:
    /**
     * @brief Сигнал, отправляемый при успешном прохождении авторизации.
     * @param role Строка, указывающая роль вошедшего пользователя («user» или «admin»).
     */
    void auth_ok(const QString& role);
    /**
     * @brief Сигнал, сообщающий об успешном создании новой учетной записи.
     */
    void reg_ok();

private:
    Ui::AuthRegForm *ui; ///< Указатель на графические элементы UI-формы.
};
#endif // AUTHREGFORM_H
