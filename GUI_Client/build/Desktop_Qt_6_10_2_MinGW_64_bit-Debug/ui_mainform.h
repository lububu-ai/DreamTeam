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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QLabel *labelChooseTask;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonTASK3;
    QPushButton *pushButtonTASK4;
    QPushButton *pushButtonTASK5;
    QPushButton *pushButtonTASK2;
    QPushButton *pushButtonTASK1;
    QPushButton *pushButtonSTATS;
    QPushButton *pushButtonEXIT;
    QPushButton *pushButtonBACK;

    void setupUi(QWidget *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName("MainForm");
        MainForm->resize(800, 600);
        labelChooseTask = new QLabel(MainForm);
        labelChooseTask->setObjectName("labelChooseTask");
        labelChooseTask->setGeometry(QRect(310, 40, 181, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rubik")});
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        labelChooseTask->setFont(font);
        labelChooseTask->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayoutWidget = new QWidget(MainForm);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(110, 120, 571, 371));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonTASK3 = new QPushButton(gridLayoutWidget);
        pushButtonTASK3->setObjectName("pushButtonTASK3");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rubik")});
        font1.setPointSize(18);
        font1.setKerning(true);
        pushButtonTASK3->setFont(font1);

        gridLayout->addWidget(pushButtonTASK3, 1, 0, 1, 1);

        pushButtonTASK4 = new QPushButton(gridLayoutWidget);
        pushButtonTASK4->setObjectName("pushButtonTASK4");
        pushButtonTASK4->setFont(font1);

        gridLayout->addWidget(pushButtonTASK4, 1, 1, 1, 1);

        pushButtonTASK5 = new QPushButton(gridLayoutWidget);
        pushButtonTASK5->setObjectName("pushButtonTASK5");
        pushButtonTASK5->setFont(font1);

        gridLayout->addWidget(pushButtonTASK5, 4, 0, 1, 1);

        pushButtonTASK2 = new QPushButton(gridLayoutWidget);
        pushButtonTASK2->setObjectName("pushButtonTASK2");
        pushButtonTASK2->setFont(font1);

        gridLayout->addWidget(pushButtonTASK2, 0, 1, 1, 1);

        pushButtonTASK1 = new QPushButton(gridLayoutWidget);
        pushButtonTASK1->setObjectName("pushButtonTASK1");
        pushButtonTASK1->setFont(font1);

        gridLayout->addWidget(pushButtonTASK1, 0, 0, 1, 1);

        pushButtonSTATS = new QPushButton(gridLayoutWidget);
        pushButtonSTATS->setObjectName("pushButtonSTATS");
        pushButtonSTATS->setFont(font1);

        gridLayout->addWidget(pushButtonSTATS, 5, 0, 1, 1);

        pushButtonEXIT = new QPushButton(gridLayoutWidget);
        pushButtonEXIT->setObjectName("pushButtonEXIT");
        pushButtonEXIT->setFont(font1);

        gridLayout->addWidget(pushButtonEXIT, 5, 1, 1, 1);

        pushButtonBACK = new QPushButton(MainForm);
        pushButtonBACK->setObjectName("pushButtonBACK");
        pushButtonBACK->setGeometry(QRect(30, 540, 171, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rubik")});
        font2.setPointSize(18);
        pushButtonBACK->setFont(font2);

        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QWidget *MainForm)
    {
        MainForm->setWindowTitle(QCoreApplication::translate("MainForm", "Form", nullptr));
        labelChooseTask->setText(QCoreApplication::translate("MainForm", "Choose a Task", nullptr));
        pushButtonTASK3->setText(QCoreApplication::translate("MainForm", "Task 3", nullptr));
        pushButtonTASK4->setText(QCoreApplication::translate("MainForm", "Task 4", nullptr));
        pushButtonTASK5->setText(QCoreApplication::translate("MainForm", "Task 5", nullptr));
        pushButtonTASK2->setText(QCoreApplication::translate("MainForm", "Task 2", nullptr));
        pushButtonTASK1->setText(QCoreApplication::translate("MainForm", "Task 1", nullptr));
        pushButtonSTATS->setText(QCoreApplication::translate("MainForm", "Stats", nullptr));
        pushButtonEXIT->setText(QCoreApplication::translate("MainForm", "Exit", nullptr));
        pushButtonBACK->setText(QCoreApplication::translate("MainForm", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
