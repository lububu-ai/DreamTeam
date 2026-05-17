/********************************************************************************
** Form generated from reading UI file 'taskform.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKFORM_H
#define UI_TASKFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskForm
{
public:

    void setupUi(QWidget *TaskForm)
    {
        if (TaskForm->objectName().isEmpty())
            TaskForm->setObjectName("TaskForm");
        TaskForm->resize(400, 300);

        retranslateUi(TaskForm);

        QMetaObject::connectSlotsByName(TaskForm);
    } // setupUi

    void retranslateUi(QWidget *TaskForm)
    {
        TaskForm->setWindowTitle(QCoreApplication::translate("TaskForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskForm: public Ui_TaskForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKFORM_H
