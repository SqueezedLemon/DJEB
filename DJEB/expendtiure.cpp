#include "expendtiure.h"
#include "ui_expendtiure.h"

Expendtiure::Expendtiure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Expendtiure)
{
    ui->setupUi(this);
}

Expendtiure::~Expendtiure()
{
    delete ui;
}
