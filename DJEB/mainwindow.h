#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"second.h"
#include <QMainWindow>
#include "newaccount.h"
#include "QtSql"
#include "QtDebug"
#include "QFileInfo"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    Second *second;
    Newaccount *newaccount;

    bool createTable();
};

#endif // MAINWINDOW_H
