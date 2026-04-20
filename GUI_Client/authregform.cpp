#include "authregform.h"
#include "clientfuncs.h"
#include "ui_authregform.h"

AuthRegForm::AuthRegForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuthRegForm)
{
    ui->setupUi(this);
    ui->labelConfirmPW->setVisible(false);
    ui->labelEmail->setVisible(false);
    ui->lineEditConfirmPW->setVisible(false);
    ui->lineEditEmail->setVisible(false);

    ui->pushButtonChangeToAUTH->setVisible(false);
    ui->pushButtonReg->setVisible(false);
}

AuthRegForm::~AuthRegForm()
{
    delete ui;
}

void AuthRegForm::on_pushButtonAuth_clicked(){
    QString log = ui->lineEditLogin->text();
    QString pw = ui->lineEditPassword->text();

    if(auth(log,pw)){
        emit auth_ok();
        this->hide();
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Wrong login/password!");
        msgBox.exec();
    }
}

void AuthRegForm::on_pushButtonReg_clicked(){
    QString log = ui->lineEditLogin->text();
    QString email = ui->lineEditEmail->text();
    QString pw = ui->lineEditPassword->text();
    QString pwConfirm = ui->lineEditConfirmPW->text();

    if(pw!=pwConfirm) {
        QMessageBox msgBox;
        msgBox.setText("Passwords are different!");
        msgBox.exec();
    }
    else{
        if(reg(log,email,pw)){
            emit reg_ok();
            QMessageBox msgBox;
            msgBox.setText("Successfully registered!");
            msgBox.exec();
        }
        else{
            QMessageBox msgBox;
            msgBox.setText("Registration failed: Not enough arguments/login occupied");
            msgBox.exec();
        }
    }
}

void AuthRegForm::on_pushButtonChangeToREG_clicked(){
    ui->labelConfirmPW->setVisible(true);
    ui->labelEmail->setVisible(true);
    ui->lineEditConfirmPW->setVisible(true);
    ui->lineEditEmail->setVisible(true);

    ui->pushButtonChangeToAUTH->setVisible(true);
    ui->pushButtonReg->setVisible(true);

    ui->pushButtonChangeToREG->setVisible(false);
    ui->pushButtonAuth->setVisible(false);
}

void AuthRegForm::on_pushButtonChangeToAUTH_clicked(){
    ui->labelConfirmPW->setVisible(false);
    ui->labelEmail->setVisible(false);
    ui->lineEditConfirmPW->setVisible(false);
    ui->lineEditEmail->setVisible(false);

    ui->pushButtonChangeToAUTH->setVisible(false);
    ui->pushButtonReg->setVisible(false);

    ui->pushButtonChangeToREG->setVisible(true);
    ui->pushButtonAuth->setVisible(true);
}



