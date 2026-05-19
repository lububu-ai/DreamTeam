#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QMessageBox>

#include "clientfuncs.h"

namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();

private:
    Ui::MainForm *ui;
    void changeToTask(bool flag);
    QString task_num{"0"};

private slots:
    void on_pushButtonTASK1_clicked();
    void on_pushButtonTASK2_clicked();
    void on_pushButtonTASK3_clicked();
    void on_pushButtonTASK4_clicked();
    void on_pushButtonTASK5_clicked();
    void on_pushButtonEXIT_clicked();
    void on_pushButtonBACK_clicked();
    void on_pushButtonSTATS_clicked();
    void on_pushButtonSendAnswer_clicked();
/*signals:
    void taskChoice_ok();*/
};

#endif // MAINFORM_H
