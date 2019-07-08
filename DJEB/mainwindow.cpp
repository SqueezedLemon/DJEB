#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QPixmap>
#include "second.h"
#include "newaccount.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap pix(":/resources/img/Background.png");
    int w = ui->label_background->width();
    int h = ui->label_background->height();
    ui->label_background->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
     mydb=QSqlDatabase::addDatabase("QSQLITE");
     mydb.setDatabaseName("ram.db");
    if(!mydb.open())
        ui->label->setText("failed to open database");
    else {
        ui->label->setText("connected..");
        createTable();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString Username,Password;
    Username=ui->lineEdit_Username->text();
    Password=ui->lineEdit_Password->text();

    if(!mydb.open())
    {
        qDebug()<<"failed to open database";
        return;
    }
    QSqlQuery qry;

    if(qry.exec("select * from information where username='"+Username+"'and password='"+Password+"'"))
    {

        if(qry.next())
           {

            ui->label->setText("username and password is correct");
            qDebug()<<"username and password is correct";
            this->hide();
            second=new Second(this);
            second->show();
        }else{
            ui->label->setText("username and password is incorrect");
            qDebug()<<"failed";
        }
    }else{
        qDebug()<<qry.lastError();
    }
}

bool MainWindow::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE information(id INTEGER PRIMARY KEY, username TEXT,password TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'user': one might already exist.";
        success = false;
    }

    return success;
}




void MainWindow::on_pushButton_2_clicked()
{
 newaccount=new Newaccount(this);
 newaccount->show();
}
