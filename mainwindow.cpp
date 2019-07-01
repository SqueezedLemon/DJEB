#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QPixmap>
#include "second.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/Background.png");
    int w = ui->label_background->width();
    int h = ui->label_background->height();
    ui->label_background->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString Username = ui->lineEdit_Username->text();
    QString Password = ui->lineEdit_Password->text();

    if (Username == "test" && Password == "test" || Username == "cracks" && Password == "cracks")
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
