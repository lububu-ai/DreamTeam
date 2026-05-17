/********************************************************************************
** Form generated from reading UI file 'authregform.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHREGFORM_H
#define UI_AUTHREGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthRegForm
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditPassword;
    QLineEdit *lineEditLogin;
    QLabel *labelConfirmPW;
    QLabel *labelLogin;
    QLabel *labelPassword;
    QLineEdit *lineEditConfirmPW;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonAuth;
    QPushButton *pushButtonReg;
    QPushButton *pushButtonChangeToREG;
    QPushButton *pushButtonChangeToAUTH;

    void setupUi(QWidget *AuthRegForm)
    {
        if (AuthRegForm->objectName().isEmpty())
            AuthRegForm->setObjectName("AuthRegForm");
        AuthRegForm->resize(800, 600);
        QFont font;
        font.setFamilies({QString::fromUtf8("Rubik")});
        font.setPointSize(14);
        AuthRegForm->setFont(font);
        gridLayoutWidget = new QWidget(AuthRegForm);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(130, 90, 541, 371));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEditPassword = new QLineEdit(gridLayoutWidget);
        lineEditPassword->setObjectName("lineEditPassword");

        gridLayout->addWidget(lineEditPassword, 1, 1, 1, 1);

        lineEditLogin = new QLineEdit(gridLayoutWidget);
        lineEditLogin->setObjectName("lineEditLogin");

        gridLayout->addWidget(lineEditLogin, 0, 1, 1, 1);

        labelConfirmPW = new QLabel(gridLayoutWidget);
        labelConfirmPW->setObjectName("labelConfirmPW");

        gridLayout->addWidget(labelConfirmPW, 2, 0, 1, 1);

        labelLogin = new QLabel(gridLayoutWidget);
        labelLogin->setObjectName("labelLogin");

        gridLayout->addWidget(labelLogin, 0, 0, 1, 1);

        labelPassword = new QLabel(gridLayoutWidget);
        labelPassword->setObjectName("labelPassword");

        gridLayout->addWidget(labelPassword, 1, 0, 1, 1);

        lineEditConfirmPW = new QLineEdit(gridLayoutWidget);
        lineEditConfirmPW->setObjectName("lineEditConfirmPW");

        gridLayout->addWidget(lineEditConfirmPW, 2, 1, 1, 1);

        labelEmail = new QLabel(gridLayoutWidget);
        labelEmail->setObjectName("labelEmail");

        gridLayout->addWidget(labelEmail, 3, 0, 1, 1);

        lineEditEmail = new QLineEdit(gridLayoutWidget);
        lineEditEmail->setObjectName("lineEditEmail");

        gridLayout->addWidget(lineEditEmail, 3, 1, 1, 1);

        horizontalLayoutWidget = new QWidget(AuthRegForm);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(40, 480, 713, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonAuth = new QPushButton(horizontalLayoutWidget);
        pushButtonAuth->setObjectName("pushButtonAuth");

        horizontalLayout->addWidget(pushButtonAuth);

        pushButtonReg = new QPushButton(horizontalLayoutWidget);
        pushButtonReg->setObjectName("pushButtonReg");

        horizontalLayout->addWidget(pushButtonReg);

        pushButtonChangeToREG = new QPushButton(horizontalLayoutWidget);
        pushButtonChangeToREG->setObjectName("pushButtonChangeToREG");

        horizontalLayout->addWidget(pushButtonChangeToREG);

        pushButtonChangeToAUTH = new QPushButton(horizontalLayoutWidget);
        pushButtonChangeToAUTH->setObjectName("pushButtonChangeToAUTH");

        horizontalLayout->addWidget(pushButtonChangeToAUTH);


        retranslateUi(AuthRegForm);

        QMetaObject::connectSlotsByName(AuthRegForm);
    } // setupUi

    void retranslateUi(QWidget *AuthRegForm)
    {
        AuthRegForm->setWindowTitle(QCoreApplication::translate("AuthRegForm", "AuthRegForm", nullptr));
        labelConfirmPW->setText(QCoreApplication::translate("AuthRegForm", "Confirm Password", nullptr));
        labelLogin->setText(QCoreApplication::translate("AuthRegForm", "Login", nullptr));
        labelPassword->setText(QCoreApplication::translate("AuthRegForm", "Password", nullptr));
        labelEmail->setText(QCoreApplication::translate("AuthRegForm", "Email", nullptr));
        pushButtonAuth->setText(QCoreApplication::translate("AuthRegForm", "Authorize", nullptr));
        pushButtonReg->setText(QCoreApplication::translate("AuthRegForm", "Register", nullptr));
        pushButtonChangeToREG->setText(QCoreApplication::translate("AuthRegForm", "Don't have an account?", nullptr));
        pushButtonChangeToAUTH->setText(QCoreApplication::translate("AuthRegForm", "Already signed in?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthRegForm: public Ui_AuthRegForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHREGFORM_H
