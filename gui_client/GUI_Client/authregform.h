#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QWidget>
#include <QMessageBox>
#include "clientfuncs.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class AuthRegForm;
}
QT_END_NAMESPACE

class AuthRegForm : public QWidget
{
    Q_OBJECT

public:
    AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();

private slots:
    void on_pushButtonAuth_clicked();
    void on_pushButtonChangeToREG_clicked();
    void on_pushButtonChangeToAUTH_clicked();
    void on_pushButtonReg_clicked();
signals:
    void auth_ok(const QString& role);
    void reg_ok();

private:
    Ui::AuthRegForm *ui;
};
#endif // AUTHREGFORM_H
