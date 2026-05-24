#include "clientfuncs.h"
#include "adminform.h"
#include "ui_adminform.h"
/**
 * @file adminform.cpp
 * @brief Реализация логики панели управления администратора.
 */

/**
 * @brief Конструктор формы AdminForm.
 * @param parent Указатель на родительский виджет.
 */
AdminForm::AdminForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminForm)
{
    ui->setupUi(this);
    ui->pushButtonBack->setVisible(false);
    ui->pushButtonDeleteUser->setVisible(false);
    ui->labelLogin->setVisible(false);
    ui->labelAllStats->setVisible(false);
    ui->labelStats->setVisible(false);
    ui->lineEditLogin->setVisible(false);
}

/**
 * @brief Деструктор класса AdminForm.
 */
AdminForm::~AdminForm()
{
    delete ui;
}

/**
 * @brief Сброс состояния панелей интерфейса администрирования. Скрывает все динамические элементы управления.
 */
void AdminForm::changeToPanel(){
    ui->pushButtonBack->setVisible(false);
    ui->pushButtonDeleteUser->setVisible(false);
    ui->labelLogin->setVisible(false);
    ui->labelAllStats->setVisible(false);
    ui->labelStats->setVisible(false);
    ui->lineEditLogin->setVisible(false);

    ui->lineEditLogin->setText("");
    ui->labelAllStats->setText("");
};

/**
 * @brief Включение интерфейса удаления пользователя.
 */
void AdminForm::on_pushButtonDelete_clicked(){
    changeToPanel();
    ui->pushButtonBack->setVisible(true);
    ui->pushButtonDeleteUser->setVisible(true);
    ui->labelLogin->setVisible(true);
    ui->lineEditLogin->setVisible(true);
};

/**
 * @brief Слот выхода из панели администратора.
 */
void AdminForm::on_pushButtonExit_clicked(){
    this->close();
};

/**
 * @brief Слот запроса и генерации таблицы общей статистики по всем пользователям системы.
 */
void AdminForm::on_pushButtonStats_clicked(){
    changeToPanel();
    ui->pushButtonBack->setVisible(true);
    ui->labelAllStats->setVisible(true);
    ui->labelStats->setVisible(true);

    QString stats = getAllStats();
    QString ready_data = getStatsTable(stats);

    QFont monoFont("Courier New");
    monoFont.setPointSize(10);

    ui->labelAllStats->setFont(monoFont);
    ui->labelAllStats->setAlignment(Qt::AlignTop);
    ui->labelAllStats->setText(ready_data);
};

/**
 * @brief Слот получения топ-10 пользователей. Проверяет права доступа и рендерит таблицу.
 */
void AdminForm::on_pushButtonTop10_clicked(){
    changeToPanel();
    ui->pushButtonBack->setVisible(true);
    ui->labelAllStats->setVisible(true);
    ui->labelStats->setVisible(true);

    QString stats = getTop10Stats();
    if (stats != "top10_stat_access_denied\r\n") {
        QString ready_data = getStatsTable(stats);

        QFont monoFont("Courier New");
        monoFont.setPointSize(10);

        ui->labelAllStats->setFont(monoFont);
        ui->labelAllStats->setAlignment(Qt::AlignTop);
        ui->labelAllStats->setText(ready_data);
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Недостаточно прав!");
        msgBox.exec();
        this->close();
    }
};

/**
 * @brief Слот подтверждения удаления пользователя по введенному логину.
 */
void AdminForm::on_pushButtonDeleteUser_clicked(){
    QString login = ui->lineEditLogin->text();

    if(delete_user(login)){
        ui->lineEditLogin->setText("");
        QMessageBox msgBox;
        msgBox.setText("Пользователь успешно удалён!(если он существовал)");
        msgBox.exec();
    }
    QMessageBox msgBox;
    msgBox.setText("Недостаточно прав!");
    msgBox.exec();
};

/**
 * @brief Возврат из вложенных панелей управления обратно в главное меню администрирования.
 */
void AdminForm::on_pushButtonBack_clicked(){
    changeToPanel();
};


