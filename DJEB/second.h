#ifndef SECOND_H
#define SECOND_H

#include <QDialog>
#include "changepassword.h"
#include "dailyjournal.h"
#include "expendtiure.h"


namespace Ui {
class Second;
}

class Second : public QDialog
{
    Q_OBJECT

public:
    explicit Second(QWidget *parent = nullptr);
    ~Second();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Second *ui;
    Changepassword *changepassword;
    Dailyjournal *dailyjournal;
    Expendtiure *expendiure;


};

#endif // SECOND_H
