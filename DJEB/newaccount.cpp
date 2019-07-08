#include "newaccount.h"
#include "ui_newaccount.h"

Newaccount::Newaccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Newaccount)
{
    ui->setupUi(this);
}

Newaccount::~Newaccount()
{
    delete ui;
}
