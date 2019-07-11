#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include<QMessageBox>
Dbase::Dbase(const QString &path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open()){
        qDebug() << "Error: connection with dbase fail";
    }else{
        qDebug() << "dbase: connection ok";
    }
}

Dbase::~Dbase()
{
    if (db.isOpen())
    {
        db.close();
    }
}

void Dbase::useradd(const QString Username,const QString Password ){

QSqlQuery qry;
qry.prepare("INSERT INTO Login(Username,Password) VALUES(:UserName,:Password)");
qry.bindValue(":UserName",Username);
qry.bindValue(":Password",Password);

if(!qry.exec()){
    qDebug() << "add user failed: " << qry.lastError();
}else{
    qDebug() << "add user success " << qry.lastError();
}
}
bool Dbase::unameExists(const QString &Username)
{
    bool success= false;
    QSqlQuery query;
    query.prepare("select * from Login where Username='"+Username+"';");
    if (query.exec())
    {
        qDebug() << "Username already exists.";
        success = true;
    }
    return success;
}
bool Dbase::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE Login( Username TEXT,Password TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'user': one might already exist.";
        success = false;
    }

    return success;
}

void Dbase::createTable(const QString Username)
{


    QSqlQuery query;
    query.prepare("CREATE TABLE '"+Username+"'( Date TEXT,DailyJournal TEXT,);");


}
