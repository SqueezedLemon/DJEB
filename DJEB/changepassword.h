#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>

namespace Ui {
class Changepassword;
}

class Changepassword : public QDialog
{
    Q_OBJECT

public:
    explicit Changepassword(QWidget *parent = nullptr);
    ~Changepassword();

private:
    Ui::Changepassword *ui;
};

#endif // CHANGEPASSWORD_H
