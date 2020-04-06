#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

a_recorder1 = new QAudioRecorder;
    a_recorder2 = new QAudioRecorder;
    a_recorder3 = new QAudioRecorder;
    a_recorder4 = new QAudioRecorder;
 m_player1=new QMediaPlayer;
    m_player2=new QMediaPlayer;
    m_player3=new QMediaPlayer;
    m_player4=new QMediaPlayer;
