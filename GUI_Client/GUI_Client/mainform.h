#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QMessageBox>

#include "clientfuncs.h"

namespace Ui {
class MainForm;
}

/**
 * @file mainform.h
 * @brief Окно личного кабинета и работы с задачами для обычного пользователя.
 */

/**
 * @class MainForm
 * @brief Класс формы основного интерфейса пользователя.
 * * Предоставляет возможность выбора одного из 5 типов задач, просмотра личной статистики,
 * отображения условий математических задач и отправки ответов на проверку.
 */
class MainForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор главной формы пользователя.
     * @param parent Указатель на родительский виджет.
     */
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();

private:
    Ui::MainForm *ui; ///< Указатель на UI-дизайн формы.
    /**
     * @brief Переключение состояния интерфейса между меню выбора задач и экраном решения конкретной задачи.
     * @param flag Если true — открывается экран решения задачи, если false — главное меню.
     */
    void changeToTask(bool flag);
    QString task_num{"0"}; ///< Строковое поле для хранения номера активного типа задачи (1-5).

private slots:
    void on_pushButtonTASK1_clicked(); ///< Слот выбора задачи типа 1 (Формула Симпсона).
    void on_pushButtonTASK2_clicked(); ///< Слот выбора задачи типа 2 (Метод хорд).
    void on_pushButtonTASK3_clicked(); ///< Слот выбора задачи типа 3 (Метод дихотомии).
    void on_pushButtonTASK4_clicked(); ///< Слот выбора задачи типа 4 (Листья дерева DFS).
    void on_pushButtonTASK5_clicked(); ///< Слот выбора задачи типа 5 (Вычисление функции).
    /**
     * @brief Слот кнопки «Выход». Осуществляет логаут и закрытие сессии.
     */
    void on_pushButtonEXIT_clicked();
    /**
     * @brief Слот возврата назад из экрана решения задачи в общее меню выбора.
     */
    void on_pushButtonBACK_clicked();
    /**
     * @brief Слот запроса и отображения всплывающего окна с персональной статистикой.
     */
    void on_pushButtonSTATS_clicked();
    /**
     * @brief Слот считывания строки ввода ответа и отправки её на проверку серверу.
     */
    void on_pushButtonSendAnswer_clicked();
/*signals:
    void taskChoice_ok();*/
};

#endif // MAINFORM_H
