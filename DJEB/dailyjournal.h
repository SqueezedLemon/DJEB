#ifndef DAILYJOURNAL_H
#define DAILYJOURNAL_H

#include <QDialog>

namespace Ui {
class Dailyjournal;
}

class Dailyjournal : public QDialog
{
    Q_OBJECT

public:
    explicit Dailyjournal(QWidget *parent = nullptr);
    ~Dailyjournal();

private:
    Ui::Dailyjournal *ui;
};

#endif // DAILYJOURNAL_H
