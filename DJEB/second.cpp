#include "second.h"
#include "ui_second.h"
#include "changepassword.h"
#include "dailyjournal.h"
#include "expendtiure.h"


Second::Second(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Second)
{
    ui->setupUi(this);
}

Second::~Second()
{
    delete ui;
}

void Second::on_pushButton_3_clicked()
{
    changepassword =new Changepassword(this);
    changepassword->show();

}

void Second::on_pushButton_clicked()
{
  dailyjournal =new Dailyjournal(this);
  dailyjournal->show();
}

void Second::on_pushButton_2_clicked()
{
      expendiure =new Expendtiure(this);
      expendiure->show();
}
