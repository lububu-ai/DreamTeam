#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>

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
    void changeHeader(char button);

private slots:
    void on_pushButtonTASK1_clicked();
    void on_pushButtonTASK2_clicked();
    void on_pushButtonTASK3_clicked();
    void on_pushButtonTASK4_clicked();
    void on_pushButtonTASK5_clicked();
    void on_pushButtonEXIT_clicked();
    void on_pushButtonBACK_clicked();
    void on_pushButtonSTATS_clicked();

};

#endif // MAINFORM_H
