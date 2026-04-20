/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QPushButton *pushButtonBACK;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelChooseTask;
    QLabel *labelTask1;
    QLabel *labelTask2;
    QLabel *labelTask3;
    QLabel *labelTask4;
    QLabel *labelTask5;
    QLabel *labelStats;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelToDo;
    QLabel *labelShowStats;
    QGridLayout *gridLayout;
    QPushButton *pushButtonTASK2;
    QPushButton *pushButtonTASK4;
    QPushButton *pushButtonEXIT;
    QPushButton *pushButtonSendAnswer;
    QPushButton *pushButtonTASK5;
    QLineEdit *lineEditAnswer;
    QPushButton *pushButtonSTATS;
    QPushButton *pushButtonTASK3;
    QPushButton *pushButtonTASK1;

    void setupUi(QWidget *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName("MainForm");
        MainForm->resize(800, 600);
        QFont font;
        font.setFamilies({QString::fromUtf8("Rubik")});
        font.setPointSize(16);
        MainForm->setFont(font);
        pushButtonBACK = new QPushButton(MainForm);
        pushButtonBACK->setObjectName("pushButtonBACK");
        pushButtonBACK->setGeometry(QRect(30, 540, 171, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rubik")});
        font1.setPointSize(18);
        pushButtonBACK->setFont(font1);
        horizontalLayoutWidget = new QWidget(MainForm);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(64, 20, 671, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelChooseTask = new QLabel(horizontalLayoutWidget);
        labelChooseTask->setObjectName("labelChooseTask");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rubik")});
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        labelChooseTask->setFont(font2);
        labelChooseTask->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(labelChooseTask);

        labelTask1 = new QLabel(horizontalLayoutWidget);
        labelTask1->setObjectName("labelTask1");
        labelTask1->setFont(font);
        labelTask1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(labelTask1);

        labelTask2 = new QLabel(horizontalLayoutWidget);
        labelTask2->setObjectName("labelTask2");
        labelTask2->setFont(font);
        labelTask2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(labelTask2);

        labelTask3 = new QLabel(horizontalLayoutWidget);
        labelTask3->setObjectName("labelTask3");
        labelTask3->setFont(font);
        labelTask3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(labelTask3);

        labelTask4 = new QLabel(horizontalLayoutWidget);
        labelTask4->setObjectName("labelTask4");
        labelTask4->setFont(font);
        labelTask4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(labelTask4);

        labelTask5 = new QLabel(horizontalLayoutWidget);
        labelTask5->setObjectName("labelTask5");
        labelTask5->setFont(font);
        labelTask5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(labelTask5);

        labelStats = new QLabel(horizontalLayoutWidget);
        labelStats->setObjectName("labelStats");
        labelStats->setFont(font);
        labelStats->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(labelStats);

        verticalLayoutWidget = new QWidget(MainForm);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(130, 150, 541, 359));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelToDo = new QLabel(verticalLayoutWidget);
        labelToDo->setObjectName("labelToDo");
        labelToDo->setFont(font);
        labelToDo->setAlignment(Qt::AlignmentFlag::AlignJustify|Qt::AlignmentFlag::AlignVCenter);
        labelToDo->setWordWrap(true);

        verticalLayout->addWidget(labelToDo);

        labelShowStats = new QLabel(verticalLayoutWidget);
        labelShowStats->setObjectName("labelShowStats");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Rubik")});
        font3.setPointSize(30);
        labelShowStats->setFont(font3);
        labelShowStats->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelShowStats->setWordWrap(true);

        verticalLayout->addWidget(labelShowStats);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButtonTASK2 = new QPushButton(verticalLayoutWidget);
        pushButtonTASK2->setObjectName("pushButtonTASK2");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Rubik")});
        font4.setPointSize(18);
        font4.setKerning(true);
        pushButtonTASK2->setFont(font4);

        gridLayout->addWidget(pushButtonTASK2, 0, 1, 1, 1);

        pushButtonTASK4 = new QPushButton(verticalLayoutWidget);
        pushButtonTASK4->setObjectName("pushButtonTASK4");
        pushButtonTASK4->setFont(font4);

        gridLayout->addWidget(pushButtonTASK4, 1, 1, 1, 1);

        pushButtonEXIT = new QPushButton(verticalLayoutWidget);
        pushButtonEXIT->setObjectName("pushButtonEXIT");
        pushButtonEXIT->setFont(font4);

        gridLayout->addWidget(pushButtonEXIT, 5, 1, 1, 1);

        pushButtonSendAnswer = new QPushButton(verticalLayoutWidget);
        pushButtonSendAnswer->setObjectName("pushButtonSendAnswer");
        pushButtonSendAnswer->setFont(font);

        gridLayout->addWidget(pushButtonSendAnswer, 6, 1, 1, 1);

        pushButtonTASK5 = new QPushButton(verticalLayoutWidget);
        pushButtonTASK5->setObjectName("pushButtonTASK5");
        pushButtonTASK5->setFont(font4);

        gridLayout->addWidget(pushButtonTASK5, 4, 0, 1, 1);

        lineEditAnswer = new QLineEdit(verticalLayoutWidget);
        lineEditAnswer->setObjectName("lineEditAnswer");
        lineEditAnswer->setFont(font);

        gridLayout->addWidget(lineEditAnswer, 6, 0, 1, 1);

        pushButtonSTATS = new QPushButton(verticalLayoutWidget);
        pushButtonSTATS->setObjectName("pushButtonSTATS");
        pushButtonSTATS->setFont(font4);

        gridLayout->addWidget(pushButtonSTATS, 5, 0, 1, 1);

        pushButtonTASK3 = new QPushButton(verticalLayoutWidget);
        pushButtonTASK3->setObjectName("pushButtonTASK3");
        pushButtonTASK3->setFont(font4);

        gridLayout->addWidget(pushButtonTASK3, 1, 0, 1, 1);

        pushButtonTASK1 = new QPushButton(verticalLayoutWidget);
        pushButtonTASK1->setObjectName("pushButtonTASK1");
        pushButtonTASK1->setFont(font4);

        gridLayout->addWidget(pushButtonTASK1, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QWidget *MainForm)
    {
        MainForm->setWindowTitle(QCoreApplication::translate("MainForm", "Form", nullptr));
        pushButtonBACK->setText(QCoreApplication::translate("MainForm", "Back", nullptr));
        labelChooseTask->setText(QCoreApplication::translate("MainForm", "Choose a Task", nullptr));
        labelTask1->setText(QCoreApplication::translate("MainForm", "Task 1", nullptr));
        labelTask2->setText(QCoreApplication::translate("MainForm", "Task 2", nullptr));
        labelTask3->setText(QCoreApplication::translate("MainForm", "Task 3", nullptr));
        labelTask4->setText(QCoreApplication::translate("MainForm", "Task 4", nullptr));
        labelTask5->setText(QCoreApplication::translate("MainForm", "Task 5", nullptr));
        labelStats->setText(QCoreApplication::translate("MainForm", "Stats", nullptr));
        labelToDo->setText(QCoreApplication::translate("MainForm", "USLOVIE", nullptr));
        labelShowStats->setText(QCoreApplication::translate("MainForm", "STATISTIKA", nullptr));
        pushButtonTASK2->setText(QCoreApplication::translate("MainForm", "Task 2", nullptr));
        pushButtonTASK4->setText(QCoreApplication::translate("MainForm", "Task 4", nullptr));
        pushButtonEXIT->setText(QCoreApplication::translate("MainForm", "Exit", nullptr));
        pushButtonSendAnswer->setText(QCoreApplication::translate("MainForm", "Send", nullptr));
        pushButtonTASK5->setText(QCoreApplication::translate("MainForm", "Task 5", nullptr));
        lineEditAnswer->setText(QString());
        pushButtonSTATS->setText(QCoreApplication::translate("MainForm", "Stats", nullptr));
        pushButtonTASK3->setText(QCoreApplication::translate("MainForm", "Task 3", nullptr));
        pushButtonTASK1->setText(QCoreApplication::translate("MainForm", "Task 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
