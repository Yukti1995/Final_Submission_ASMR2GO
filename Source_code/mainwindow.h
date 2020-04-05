#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer> //Libraries to play music
#include <QMediaPlaylist>
#include <QAudioRecorder> //Library to rrecord audio
#include "ui_mainwindow.h" 

QAudioRecorder *a_recorder1 = nullptr;
    QAudioRecorder *a_recorder2 = nullptr;//4 objects of audio rcorder for 4 recording buttons
    QAudioRecorder *a_recorder3 = nullptr;
    QAudioRecorder *a_recorder4 = nullptr;


void recordMusic1()   //function to record music
    {
    
        switch (a_recorder1->state()) {
        case QAudioRecorder::RecordingState:  //If it's already recording and we click button then it stops recording
            a_recorder1->stop();
            break;
                
                
        case QAudioRecorder::PausedState://otherwise if not recording and you click button then it starts recording
        case QAudioRecorder::StoppedState:
            QAudioEncoderSettings audioSettings;
                
                
              
            audioSettings.setCodec("audio/amr");
            audioSettings.setQuality(QMultimedia::HighQuality);
            a_recorder1->record();
            break;
        }
    }
