#include "clientfuncs.h"
#include "mainform.h"
#include "ui_mainform.h"
//ответы с точностью до 6 числа после запятой
MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainForm)
{
    ui->setupUi(this);
    ui->pushButtonBACK->setVisible(false);
    ui->labelStats->setVisible(false);
    ui->labelTask1->setVisible(false);
    ui->labelTask2->setVisible(false);
    ui->labelTask3->setVisible(false);
    ui->labelTask4->setVisible(false);
    ui->labelTask5->setVisible(false);
    ui->labelToDo->setVisible(false);
    ui->pushButtonSendAnswer->setVisible(false);
    ui->lineEditAnswer->setVisible(false);
    ui->labelShowStats->setVisible(false);
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
    ui->lineEditAnswer->setVisible(!flag);
    ui->pushButtonSendAnswer->setVisible(!flag);
    ui->labelToDo->setVisible(!flag);
    ui->pushButtonSendAnswer->setVisible(!flag);
    ui->lineEditAnswer->setVisible(!flag);

    ui->labelShowStats->setVisible(false);
    ui->labelStats->setVisible(false);
    ui->labelTask1->setVisible(false);
    ui->labelTask2->setVisible(false);
    ui->labelTask3->setVisible(false);
    ui->labelTask4->setVisible(false);
    ui->labelTask5->setVisible(false);

    task_num = "0";
}


void MainForm::on_pushButtonTASK1_clicked(){//Musikhin
    //Дано: Функция, шаг h, значения в трех точках y₀, y₁, y₂.
    //Найти: интеграл на двойном отрезке [x₀, x₂] методом Симпсона.
    changeToTask(false);
    task_num = "1";
    ui->labelTask1->setVisible(true);
    QString ars = getTask(task_num);

    QVector<QString> args(4);
    extractArgs(ars,args);

    QString uslovie = "Дано: Функция,\r\nшаг h=%1,\r\nзначения в трех точках y₀=%2, y₁=%3, y₂=%4"
                      "\r\nНайти: интеграл на двойном отрезке [x₀, x₂] методом Симпсона.";

    uslovie = uslovie.arg(args[0])
                  .arg(args[1])
                  .arg(args[2])
                  .arg(args[3]);


    ui->labelToDo->setText(uslovie);

}

void MainForm::on_pushButtonTASK2_clicked(){//Filatov
    //Дано: Функция, значения на концах отрезка f(a) и f(b).
    //Найти: точку пересечения хорды с осью OX.
    changeToTask(false);
    task_num = "2";
    ui->labelTask2->setVisible(true);
    QString ars = getTask(task_num);

    QVector<QString> args(5);
    extractArgs(ars,args);

    QString uslovie = "Дано: Функция f(x)=%1, \r\na=%2, b=%3, значения на концах отрезка f(a)=%4 и f(b)=%5."
                      "\r\nНайти: точку пересечения хорды с осью OX.";

    uslovie = uslovie.arg(args[0])
                  .arg(args[1])
                  .arg(args[2])
                  .arg(args[3])
                  .arg(args[4]);


    ui->labelToDo->setText(uslovie);
}

void MainForm::on_pushButtonTASK3_clicked(){//Shilova
    //Дано: Функция, отрезок [a, b], количество итераций k.
    //Найти: длину итогового отрезка после k итераций.
    changeToTask(false);
    task_num = "3";
    ui->labelTask3->setVisible(true);
    QString ars = getTask(task_num);

    QVector<QString> args(3);
    extractArgs(ars,args);

    QString uslovie = "Дано: Функция, отрезок [%1, %2], количество итераций k = %3.\r\n "
                      "Найти: длину итогового отрезка после k итераций.";

    uslovie = uslovie.arg(args[0])
                  .arg(args[1])
                  .arg(args[2]);

    ui->labelToDo->setText(uslovie);


}

void MainForm::on_pushButtonTASK4_clicked(){//Semenets
    //Дано: Дерево, корневая вершина.
    //Найти: список листьев.
    changeToTask(false);
    task_num = "4";
    ui->labelTask4->setVisible(true);
    QString ars = getTask(task_num);
    QVector<QString> args(3);
    extractArgs(ars,args);

    QString uslovie = "Дано: Дерево %1, корневая вершина %2, ребра %3.\r\nНайти список листьев";

    uslovie = uslovie.arg(args[0])
                  .arg(args[1])
                  .arg(args[2]);

    ui->labelToDo->setText(uslovie);
}

void MainForm::on_pushButtonTASK5_clicked(){//Rybakin
    //Дано: Уравнение, приведенное к виду x = φ(x), начальное приближение x₀.
    //Найти: x₁.
    changeToTask(false);
    task_num = "5";
    ui->labelTask5->setVisible(true);

    //args: a, b, c, d, x0
    QVector<QString> args(5);

    QString ars = getTask(task_num);
    extractArgs(ars, args);

    QString uslovie = "Дано уравнение вида x = φ(x):\r\nx = %1 * ln(|x0|+1) + %2 * sqrt(|%3*x0+%4|) "
                     "\r\nHачальное приближение х0 = %5. \r\nНайдите x1 методом простой итерации";

    uslovie = uslovie.arg(args[0])
        .arg(args[1])
        .arg(args[2])
        .arg(args[3])
        .arg(args[4]);

    ui->labelToDo->setText(uslovie);
}

void MainForm::on_pushButtonEXIT_clicked(){
    //Change to (LOG) OUT
    this->close();
}

void MainForm::on_pushButtonBACK_clicked(){
    changeToTask(true);
}

void MainForm::on_pushButtonSTATS_clicked(){
    changeToTask(false);
    ui->labelToDo->setVisible(false);
    ui->pushButtonSendAnswer->setVisible(false);
    ui->lineEditAnswer->setVisible(false);
    ui->labelStats->setVisible(true);
    ui->labelShowStats->setVisible(true);

    QString stats = getStats();

    ui->labelShowStats->setText
        ("1||2||3||4||5\r\n"+stats);
}

void MainForm::on_pushButtonSendAnswer_clicked(){
    QString ans = ui->lineEditAnswer->text();

    if(sendAnswer(task_num,ans)){
        QMessageBox msgBox;
        msgBox.setText("Answer is correct!");
        msgBox.exec();
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Answer is incorrect");
        msgBox.exec();
    }
}


