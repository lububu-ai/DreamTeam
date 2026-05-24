#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QWidget>
#include <QMessageBox>

#include "clientfuncs.h"

namespace Ui {
class AdminForm;
}

/**
 * @file adminform.h
 * @brief Окно панели управления для пользователей с правами администратора.
 */

/**
 * @class AdminForm
 * @brief Класс интерфейса формы администратора.
 * * Позволяет просматривать общую статистику по всем зарегистрированным пользователям,
 * выводить топ-10 лучших участников и осуществлять администрирование (удаление пользователей).
 */
class AdminForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор формы администратора.
     * @param parent Указатель на родительский виджет.
     */
    explicit AdminForm(QWidget *parent = nullptr);
    ~AdminForm();

private:
    Ui::AdminForm *ui; ///< Указатель на UI-дизайн формы администратора.
    /**
     * @brief Вспомогательный метод переключения внутренних панелей или представлений виджета.
     */
    void changeToPanel();
    QString task_num{"0"}; ///< Идентификатор выбранного элемента или задачи.

private slots:
    /**
     * @brief Слот открытия режима удаления пользователя.
     */
    void on_pushButtonDelete_clicked();
    /**
     * @brief Слот завершения работы с панелью администратора и выхода в окно авторизации.
     */
    void on_pushButtonExit_clicked();
    /**
     * @brief Слот вывода полного списка пользователей и их детальных баллов.
     */
    void on_pushButtonStats_clicked();
    /**
     * @brief Слот отображения таблицы топ-10 лучших аккаунтов.
     */
    void on_pushButtonTop10_clicked();
    /**
     * @brief Слот подтверждения операции удаления конкретного пользователя по логину.
     */
    void on_pushButtonDeleteUser_clicked();
    /**
     * @brief Слот возврата из окон просмотра таблиц назад в главное меню администратора.
     */
    void on_pushButtonBack_clicked();
};

#endif // ADMINFORM_H
