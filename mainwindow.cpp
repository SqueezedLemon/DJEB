#include "mainwindow.h"
#include "ui  mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString Username = ui->lineEdit_Username->text();
    QString Password = ui->lineEdit_Password->text();

    if (Username == "test" && Password == "test")
    {
        hide();
        second = new Second(this);
        second->show();
    }
    else
    {
        QMessageBox::warning(this,"Login","Username or Password is incorrect.");
    }
}
