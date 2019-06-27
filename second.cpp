#include "second.h"
#include "ui_second.h"

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
