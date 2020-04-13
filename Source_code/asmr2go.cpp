
#include "asmr2go.h"
#include "ui_asmr2go.h"
#include <QApplication>

ASMR2Go::ASMR2Go(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ASMR2Go)
{
    ui->setupUi(this);
    QMainWindow::showFullScreen();
    // Four objects for recording four voices from the input
    rec_1=new QAudioRecorder;
    rec_2=new QAudioRecorder;
    rec_3=new QAudioRecorder;
    rec_4=new QAudioRecorder;


   // Eight objects to play the voices at the output 

    play_1=new QMediaPlayer();
    play_2=new QMediaPlayer();
    play_3=new QMediaPlayer();
    play_4=new QMediaPlayer();
    play_5=new QMediaPlayer();
    play_6=new QMediaPlayer();
    play_7=new QMediaPlayer();
    play_8=new QMediaPlayer();

}

ASMR2Go::~ASMR2Go()
{
    delete ui;
}



