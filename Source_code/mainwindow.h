#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>//Library to build main window 
#include <QMediaPlayer> //Library to play music 
#include <QMediaPlaylist>//Library to interface with other devices
#include <QAudioRecorder> //Library to record music 
#include "ui_mainwindow.h" //header to generate .ui file for home page QT5 wizard

QAudioRecorder *a_recorder1 = nullptr;//first object for recording audio in four buttons 
    QAudioRecorder *a_recorder2 = nullptr;//second
    QAudioRecorder *a_recorder3 = nullptr;//third
    QAudioRecorder *a_recorder4 = nullptr;//four


void recordMusic1()   //function to record music in the first button 
    {
    
        switch (a_recorder1->state()) {
        case QAudioRecorder::RecordingState:  //If it's already recording and we click button then it stops recording
            a_recorder1->stop();
            break;// first object , it will automatically stop recording on pressing the button 
                
                
        case QAudioRecorder::PausedState://otherwise if not recording and you click button then it starts recording
        case QAudioRecorder::StoppedState:
            QAudioEncoderSettings audioSettings;
                
                
              
            audioSettings.setCodec("audio/asmr");
            audioSettings.setQuality(QMultimedia::HighQuality);
            a_recorder1->record();
            break;
        }
    }
