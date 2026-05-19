#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QWidget>
#include <QMessageBox>

#include "clientfuncs.h"

namespace Ui {
class AdminForm;
}

class AdminForm : public QWidget
{
    Q_OBJECT

public:
    explicit AdminForm(QWidget *parent = nullptr);
    ~AdminForm();

private:
    Ui::AdminForm *ui;
    void changeToPanel();
    QString task_num{"0"};

private slots:
    void on_pushButtonDelete_clicked();
    void on_pushButtonExit_clicked();
    void on_pushButtonStats_clicked();
    void on_pushButtonTop10_clicked();
    void on_pushButtonDeleteUser_clicked();
    void on_pushButtonBack_clicked();
};

#endif // ADMINFORM_H
