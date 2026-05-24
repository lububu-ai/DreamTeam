#include "clientfuncs.h"
#include "mainform.h"
#include "ui_mainform.h"
//ответы с точностью до 6 числа после запятой
/**
 * @file mainform.cpp
 * @brief Реализация логики главного окна личного кабинета обычного пользователя.
 */

/**
 * @brief Конструктор формы MainForm. Скрывает элементы интерфейса отображения и решения задач.
 * @param parent Указатель на родительский виджет.
 */
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

/**
 * @brief Деструктор класса MainForm.
 */
MainForm::~MainForm()
{
    delete ui;
}

/**
 * @brief Управление видимостью виджетов для переключения между меню и экраном задачи.
 * @param flag Если true — отображается меню выбора задач, если false — интерфейс ввода ответа.
 */
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

/**
 * @brief Обработчик выбора Задачи №1 (Формула Симпсона). Запрашивает данные с сервера и выводит на экран.
 */
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

/**
 * @brief Обработчик выбора Задачи №2 (Метод хорд).
 */
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

/**
 * @brief Обработчик выбора Задачи №3 (Метод дихотомии).
 */
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

/**
 * @brief Обработчик выбора Задачи №4 (Поиск листьев дерева в DFS).
 */
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

/**
 * @brief Обработчик выбора Задачи №5 (Вычисление математической функции).
 */
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

/**
 * @brief Закрытие текущей формы (выход из аккаунта).
 */
void MainForm::on_pushButtonEXIT_clicked(){
    //Change to (LOG) OUT
    this->close();
}

/**
 * @brief Кнопка возврата в меню выбора из экрана решения.
 */
void MainForm::on_pushButtonBACK_clicked(){
    changeToTask(true);
    ui->lineEditAnswer->setText("");
}

/**
 * @brief Запрос личной статистики, ее парсинг и построение текстовой таблицы достижений.
 */
void MainForm::on_pushButtonSTATS_clicked(){
    changeToTask(false);
    ui->labelToDo->setVisible(false);
    ui->pushButtonSendAnswer->setVisible(false);
    ui->lineEditAnswer->setVisible(false);
    ui->labelStats->setVisible(true);
    ui->labelShowStats->setVisible(true);

    QString stats = getStats();

    QString compactStats;

    QStringList scores = stats.split("||", Qt::SkipEmptyParts);

    QStringList displayValues;
    for (int i = 0; i < scores.size(); ++i) {
        int score = scores[i].toInt();
        if (score > 0) displayValues << QString("+%1").arg(score);
        else if (score < 0) displayValues << QString::number(score);
        else displayValues << "0";
    }

    // Находим максимальную ширину
    int maxWidth = 2; // минимум
    for (const QString& val : displayValues) {
        maxWidth = qMax(maxWidth, val.length());
    }

    // Создаем таблицу
    QString line = "+";
    for (int i = 0; i < 5; ++i) {
        line += QString("-").repeated(maxWidth + 2);
        if (i < 4) line += "+";
    }
    line += "+\r\n";

    QString header = "|";
    for (int i = 1; i <= 5; ++i) {
        header += QString(" T%1 ").arg(i).leftJustified(maxWidth + 1, ' ');
        header += "|";
    }
    header += "\r\n";

    QString values = "|";
    for (const QString& val : displayValues) {
        values += QString(" %1 ").arg(val).leftJustified(maxWidth + 2, ' ');
        values += "|";
    }
    values += "\r\n";

    int total = 0;
    for (const QString& score : scores) total += score.toInt();

    QString result = line + header + line + values + line;
    result += QString("\r\nВсего: %1").arg(total);

    QFont monoFont("Courier New");
    monoFont.setPointSize(15);

    ui->labelShowStats->setFont(monoFont);
    ui->labelShowStats->setText(result);
}

/**
 * @brief Считывание ответа и отправка серверу. Информирует пользователя о результате проверки.
 */
void MainForm::on_pushButtonSendAnswer_clicked(){
    QString ans = ui->lineEditAnswer->text();

    if(sendAnswer(task_num,ans)){
        QMessageBox msgBox;
        msgBox.setText("Ответ правильный!");
        msgBox.exec();
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Ответ неправильный!");
        msgBox.exec();
    }
}


