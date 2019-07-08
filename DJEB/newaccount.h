#ifndef NEWACCOUNT_H
#define NEWACCOUNT_H

#include <QDialog>

namespace Ui {
class Newaccount;
}

class Newaccount : public QDialog
{
    Q_OBJECT

public:
    explicit Newaccount(QWidget *parent = nullptr);
    ~Newaccount();

private:
    Ui::Newaccount *ui;
};

#endif // NEWACCOUNT_H
