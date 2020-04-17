#ifndef MYLOGIN_H
#define MYLOGIN_H

#include <QDialog>

namespace Ui {
class mylogin;
}

class mylogin : public QDialog
{
    Q_OBJECT

public:
    explicit mylogin(QWidget *parent = 0);
    ~mylogin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::mylogin *ui;
};

#endif // MYLOGIN_H
