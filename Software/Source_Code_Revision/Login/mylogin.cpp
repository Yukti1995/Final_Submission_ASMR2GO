#include "mylogin.h"
#include "ui_mylogin.h"
#include"mylogin.h"
#include<QMessageBox>

mylogin::mylogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mylogin)
{
    ui->setupUi(this);
}

mylogin::~mylogin()
{
    delete ui;
}

void mylogin::on_pushButton_clicked()
{
    QString username = ui-> Username ->text();
    QString password = ui-> Password_2 ->text();

    if (username =="manush" && password =="yukti")
    {
        QMessageBox::information(this,"Login","Username and password is correct");
    }
    else
    {
         QMessageBox::information(this,"Login","Username and password is not correct");
    }

}
