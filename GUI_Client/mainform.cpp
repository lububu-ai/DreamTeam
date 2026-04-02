#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainForm)
{
    ui->setupUi(this);
    ui->pushButtonBACK->setVisible(false);
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::changeToTask(bool flag){
    ui->labelChooseTask->setVisible(flag);
    ui->pushButtonTASK1->setVisible(flag);
    ui->pushButtonTASK2->setVisible(flag);
    ui->pushButtonTASK3->setVisible(flag);
    ui->pushButtonTASK4->setVisible(flag);
    ui->pushButtonTASK5->setVisible(flag);
    ui->pushButtonSTATS->setVisible(flag);
    ui->pushButtonEXIT->setVisible(flag);
    ui->pushButtonBACK->setVisible(!flag);
}

void MainForm::changeHeader(char button){
    switch (button) {
    case '0': break;
    case '1': break;
    }
}

void MainForm::on_pushButtonTASK1_clicked(){
    changeToTask(false);
}

void MainForm::on_pushButtonTASK2_clicked(){
    changeToTask(false);
}

void MainForm::on_pushButtonTASK3_clicked(){
    changeToTask(false);
}

void MainForm::on_pushButtonTASK4_clicked(){
    changeToTask(false);
}

void MainForm::on_pushButtonTASK5_clicked(){
    changeToTask(false);
}

void MainForm::on_pushButtonEXIT_clicked(){
    this->close();
}

void MainForm::on_pushButtonBACK_clicked(){
    changeToTask(true);
}

void MainForm::on_pushButtonSTATS_clicked(){
    changeToTask(false);
}


