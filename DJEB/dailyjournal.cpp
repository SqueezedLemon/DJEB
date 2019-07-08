#include "dailyjournal.h"
#include "ui_dailyjournal.h"

Dailyjournal::Dailyjournal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dailyjournal)
{
    ui->setupUi(this);
}

Dailyjournal::~Dailyjournal()
{
    delete ui;
}
