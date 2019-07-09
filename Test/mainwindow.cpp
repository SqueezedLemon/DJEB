#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QPixmap>
#include<QStackedWidget>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
//    QPixmap pix(":/resources/img/Background.png");
//    int w = ui->label_background->width();
//    int h = ui->label_background->height();
//    ui->label_background->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
     mydb=QSqlDatabase::addDatabase("QSQLITE");
     mydb.setDatabaseName("ram.db");
     ui->stackedWidget->setCurrentIndex(0);
      //  createTable();
     connect(ui->lineEdit_Password, SIGNAL(returnPressed()),ui->pushButton,SIGNAL(clicked()));
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
    QSqlQuery qry(mydb);

    if(qry.exec("select * from information where username='"+Username+"'and password='"+Password+"'"))
    {

       if(qry.next())
           {


            qDebug()<<"username and password is correct";
            this->close();
            clientwin = new ClientWin(this);
            clientwin->show();
        }
       else{

            qDebug()<<"failed";
            QMessageBox::warning(this,"Login","Username or Password is incorrect.");
        }
    }
}

/*bool MainWindow::createTable()
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

*/



void MainWindow::on_pushButton_SignUp_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
