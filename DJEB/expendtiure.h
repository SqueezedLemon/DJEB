#ifndef EXPENDTIURE_H
#define EXPENDTIURE_H

#include <QDialog>

namespace Ui {
class Expendtiure;
}

class Expendtiure : public QDialog
{
    Q_OBJECT

public:
    explicit Expendtiure(QWidget *parent = nullptr);
    ~Expendtiure();

private:
    Ui::Expendtiure *ui;
};

#endif // EXPENDTIURE_H
