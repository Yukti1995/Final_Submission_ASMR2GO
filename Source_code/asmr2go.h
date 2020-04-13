#ifndef ASMR2GO_H
#define ASMR2GO_H

#include <QMainWindow>//Library to build main window
#include <QMediaPlayer> //Library to play music
#include <QMediaPlaylist>//Library to interface with other devices
#include <QAudioRecorder> //Library to record music
#include "ui_mainwindow.h" //header to generate .ui file for home page QT5 wizard generation

namespace Ui {
class ASMR2Go;
}

class ASMR2Go : public QMainWindow
{
    Q_OBJECT

public:
    explicit ASMR2Go(QWidget *parent = 0);
    ~ASMR2Go();

private:
    Ui::ASMR2GO *ui;
    QAudioRecorder *rec_1 = nullptr;
    QAudioRecorder *rec_2 = nullptr;
    QAudioRecorder *rec_3 = nullptr;
    QAudioRecorder *rec_4 = nullptr;
    //
    QMediaPlayer *play_1 = nullptr;
    QMediaPlayer *play_2 = nullptr;
    QMediaPlayer *play_3 = nullptr;
    QMediaPlayer *play_4 = nullptr;
    //
    QMediaPlayer *play_5 = nullptr;
    QMediaPlayer *play_6 = nullptr;
    QMediaPlayer *play_7 = nullptr;
    QMediaPlayer *play_8 = nullptr;
    //

private slots:
    void recordMusic1()
    {
        switch (rec_1->state()) {
        case QAudioRecorder::RecordingState:
            rec_1->stop();
            break;
            //
        case QAudioRecorder::PausedState:
        case QAudioRecorder::StoppedState:
            QAudioEncoderSettings audioSettings;
            audioSettings.setCodec("audio/amr");
            audioSettings.setQuality(QMultimedia::HighQuality);
            rec_1->setEncodingSettings(audioSettings);
            rec_1->setOutputLocation(QUrl::fromLocalFile("/home/max/song1.amr"));
            rec_1->record();
            break;
            //
        }
    }
    void recordMusic2()
    {
        switch (rec_2->state()) {
        case QAudioRecorder::RecordingState:
            rec_2->stop();
            break;
            //
        case QAudioRecorder::PausedState:
        case QAudioRecorder::StoppedState:
            QAudioEncoderSettings audioSettings;
            audioSettings.setCodec("audio/amr");
            audioSettings.setQuality(QMultimedia::HighQuality);
            rec_2->setEncodingSettings(audioSettings);
            rec_2->setOutputLocation(QUrl::fromLocalFile("/home/max/song2.amr"));
            rec_2->record();
            break;
            //
        }
    }
    void recordMusic3()
    {
        switch (rec_3->state()) {
        case QAudioRecorder::RecordingState:
            rec_3->stop();
            break;
            //
        case QAudioRecorder::PausedState:
        case QAudioRecorder::StoppedState:
            QAudioEncoderSettings audioSettings;
            audioSettings.setCodec("audio/amr");
            audioSettings.setQuality(QMultimedia::HighQuality);
            rec_3->setEncodingSettings(audioSettings);
            rec_3->setOutputLocation(QUrl::fromLocalFile("/home/max/song3.amr"));
            rec_3->record();
            break;
            //
        }
    }
    void recordMusic4()
    {
        switch (rec_4->state()) {
        case QAudioRecorder::RecordingState:
            rec_4->stop();
            break;
            //
        case QAudioRecorder::PausedState:
        case QAudioRecorder::StoppedState:
            QAudioEncoderSettings audioSettings;
            audioSettings.setCodec("audio/amr");
            audioSettings.setQuality(QMultimedia::HighQuality);
            rec_4->setEncodingSettings(audioSettings);
            rec_4->setOutputLocation(QUrl::fromLocalFile("/home/max/song4.amr"));
            rec_4->record();
            break;
            //
        }
    }



    void playMusic1()
    {
        switch (play_1->state()) {
        case QMediaPlayer::PlayingState:
            play_1->stop();
            ui->pushbutton_1->setText("");
            break;
            //
        case QMediaPlayer::PausedState:
        case QMediaPlayer::StoppedState:
            QMediaPlaylist *playlist = new QMediaPlaylist();
            playlist->addMedia(QUrl::fromLocalFile("/home/max/song1.amr"));
            playlist->setPlaybackMode(QMediaPlaylist::Loop);
            play_1 = new QMediaPlayer;
            play_1->setPlaylist(playlist);
            ui->pushbutton_1->setText("...");
            play_1->play();
            break;
            //
        }
    }

    void playMusic2()
    {
        switch (play_2->state()) {
        case QMediaPlayer::PlayingState:
            play_2->stop();
            ui->pushbutton_2->setText("");
            break;
            //
        case QMediaPlayer::PausedState:
        case QMediaPlayer::StoppedState:
            QMediaPlaylist *playlist = new QMediaPlaylist();
            playlist->addMedia(QUrl::fromLocalFile("/home/max/song2.amr"));
            playlist->setPlaybackMode(QMediaPlaylist::Loop);
            play_2 = new QMediaPlayer;
            play_2->setPlaylist(playlist);
            ui->pushbutton_2->setText("...");
            play_2->play();
            break;
            //
        }
    }

      void playMusic3()
    {
        switch (play_3->state()) {
        case QMediaPlayer::PlayingState:
            play_3->stop();
            ui->pushbutton_3->setText("");
            break;
            //
        case QMediaPlayer::PausedState:
        case QMediaPlayer::StoppedState:
            QMediaPlaylist *playlist = new QMediaPlaylist();
            playlist->addMedia(QUrl::fromLocalFile("/home/max/song3.amr"));
            playlist->setPlaybackMode(QMediaPlaylist::Loop);
            play_3= new QMediaPlayer;
            play_3->setPlaylist(playlist);
            play_3->play();
            ui->pushbutton_3->setText("...");
            break;
            //
        }
    }

    void playMusic4()
    {
        switch (play_4->state()) {
        case QMediaPlayer::PlayingState:
            play_4->stop();
            ui->pushbutton_4->setText("");
            break;
            //
        case QMediaPlayer::PausedState:
        case QMediaPlayer::StoppedState:
            QMediaPlaylist *playlist = new QMediaPlaylist();
            playlist->addMedia(QUrl::fromLocalFile("/home/max/song4.amr"));
            playlist->setPlaybackMode(QMediaPlaylist::Loop);
            play_4 = new QMediaPlayer;
            play_4->setPlaylist(playlist);
            play_4->play();
            ui->pushbutton_4->setText("...");
            break;
            //
        }

    }
    void playMusic5()
    {
        switch (play_5->state()) {
        case QMediaPlayer::PlayingState:
            play_5->stop();
            ui->pushbutton_5->setText("Take_Care");
            break;
            //
        case QMediaPlayer::PausedState:
        case QMediaPlayer::StoppedState:
            QMediaPlaylist *playlist = new QMediaPlaylist();
            playlist->addMedia(QUrl::fromLocalFile("/home/manush/Documents/yukti/audio_files/Take_Care.mp3"));
            playlist->setPlaybackMode(QMediaPlaylist::Loop);
            play_5 = new QMediaPlayer;
            play_5->setPlaylist(playlist);
            play_5->play();
            ui->pushbutton_5->setText("Take_Care");
            break;
            //
        }
    }
        void playMusic6()
        {
            switch (play_6->state()) {
            case QMediaPlayer::PlayingState:
                play_6->stop();
                ui->pushbutton_6->setText("The_Lullyby");
                break;
                //
            case QMediaPlayer::PausedState:
            case QMediaPlayer::StoppedState:
                QMediaPlaylist *playlist = new QMediaPlaylist();
                playlist->addMedia(QUrl::fromLocalFile("/home/manush/Documents/yukti/audio_files/The_Lullyby.mp3"));
                playlist->setPlaybackMode(QMediaPlaylist::Loop);
                play_6 = new QMediaPlayer;
                play_6->setPlaylist(playlist);
                play_6->play();
                ui->pushbutton_6->setText("The_Lullyby");
                break;
                //
            }
        }

        void playMusic7()
        {
            switch (play_7->state()) {
            case QMediaPlayer::PlayingState:
                play_7->stop();
                ui->pushbutton_7->setText("The_Sooth");
                break;
                //
            case QMediaPlayer::PausedState:
            case QMediaPlayer::StoppedState:
                QMediaPlaylist *playlist = new QMediaPlaylist();
                playlist->addMedia(QUrl::fromLocalFile("/home/manush/Documents/yukti/Final_Submission_ASMR2GO/Software/Sound_processing/Sound_samples/The_Sooth.mp3"));
                playlist->setPlaybackMode(QMediaPlaylist::Loop);
                play_7 = new QMediaPlayer;
                play_7->setPlaylist(playlist);
                play_7->play();
                ui->pushbutton_7->setText("The_Sooth");
                break;
                //
            }
        }
        void playMusic8()
        {
            switch (play_8->state()) {
            case QMediaPlayer::PlayingState:
                play_8->stop();
                ui->pushbutton_7->setText("The_Light");
                break;
                //
            case QMediaPlayer::PausedState:
            case QMediaPlayer::StoppedState:
                QMediaPlaylist *playlist = new QMediaPlaylist();
                playlist->addMedia(QUrl::fromLocalFile("/home/manush/Documents/yukti/Final_Submission_ASMR2GO/Software/Sound_processing/Sound_samples/The_Light.mp3"));
                playlist->setPlaybackMode(QMediaPlaylist::Loop);
                play_8 = new QMediaPlayer;
                play_8->setPlaylist(playlist);
                play_8->play();
                ui->pushbutton_8->setText("The_Light");
                break;
                //
            }
        }

#endif // ASMR2GO_H


