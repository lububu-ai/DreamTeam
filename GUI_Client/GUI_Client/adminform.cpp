#include "clientfuncs.h"
#include "adminform.h"
#include "ui_adminform.h"


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

AdminForm::~AdminForm()
{
    delete ui;
}

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

void AdminForm::on_pushButtonDelete_clicked(){
    changeToPanel();
    ui->pushButtonBack->setVisible(true);
    ui->pushButtonDeleteUser->setVisible(true);
    ui->labelLogin->setVisible(true);
    ui->lineEditLogin->setVisible(true);
};

void AdminForm::on_pushButtonExit_clicked(){
    this->close();
};

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

void AdminForm::on_pushButtonBack_clicked(){
    changeToPanel();
};


