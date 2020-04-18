#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::showFullScreen();
    // Four objects for recording four voices from the input
    a_recorder1=new QAudioRecorder;
    a_recorder2=new QAudioRecorder;
    a_recorder3=new QAudioRecorder;
    a_recorder4=new QAudioRecorder;


   // Eight objects to play the voices at the output 

    m_player1=new QMediaPlayer();
    m_player2=new QMediaPlayer();
    m_player3=new QMediaPlayer();
    m_player4=new QMediaPlayer();
        //4 objects to play the ASMR voice that we are recording live 
    m_player5=new QMediaPlayer();
    m_player6=new QMediaPlayer();
    m_player7=new QMediaPlayer();
    m_player8=new QMediaPlayer();
        //4 objects to play the pre-stored ASMR voices

}

MainWindow::~MainWindow()
{
    delete ui;
}


