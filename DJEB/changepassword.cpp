#include "changepassword.h"
#include "ui_changepassword.h"

Changepassword::Changepassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Changepassword)
{
    ui->setupUi(this);
}

Changepassword::~Changepassword()
{
    delete ui;
}
