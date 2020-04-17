#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylogin.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()

{
    mylogin MyLogs;
    MyLogs.setModal(true);
    MyLogs.exec();

   MyLogin= new mylogin(this);
    hide();
   MyLogin-> show();
}
