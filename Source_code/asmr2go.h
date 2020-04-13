#ifndef ASMR2GO_H // These happen to be there by default 
#define ASMR2GO_H

#include <QMainWindow>//Library to build main window
#include <QMediaPlayer> //Library to play music
#include <QMediaPlaylist>//Library to interface with other devices
#include <QAudioRecorder> //Library to record music
#include "ui_asmr2go.h" //header to generate .ui file for home page QT5 wizard generation

namespace Ui {
class ASMR2Go;
}

class ASMR2Go : public QMainWindow // Links the program to the main GUI window 
{
    Q_OBJECT

public:
    explicit ASMR2Go(QWidget *parent = nullptr);
    ~ASMR2Go();

private: //functions can be accessed only inside the class
    Ui::ASMR2GO *ui;
    QAudioRecorder *rec_1 = nullptr;
    QAudioRecorder *rec_2 = nullptr;
    QAudioRecorder *rec_3 = nullptr;
    QAudioRecorder *rec_4 = nullptr;
    // 4 objects to process live recording on the system 
    QMediaPlayer *play_1 = nullptr;
    QMediaPlayer *play_2 = nullptr;
    QMediaPlayer *play_3 = nullptr;
    QMediaPlayer *play_4 = nullptr;
    //4 objects to process playing of 4 recorded voices 
    QMediaPlayer *play_5 = nullptr;
    QMediaPlayer *play_6 = nullptr;
    QMediaPlayer *play_7 = nullptr;
    QMediaPlayer *play_8 = nullptr;
    //my main functions()

private slots:
    void recordMusic1() // main function 1
    {
        switch (rec_1->state()) {
        case QAudioRecorder::RecordingState: // if the current state of the recorder function is already recording, this would stop it and 
                //break it out of the loop
            rec_1->stop();
            break;
          
        case QAudioRecorder::PausedState://when the current state of recorder is paused, it is allowed to go in the stopped state and 
                //with an adaptive Multi Rate format the object rec_1 on pushing it starts to record 
        case QAudioRecorder::StoppedState:
            QAudioEncoderSettings audioSettings;
            audioSettings.setCodec("audio/amr");// amr , audio compression format for live speech signals 
            audioSettings.setQuality(QMultimedia::HighQuality);
            rec_1->setEncodingSettings(audioSettings);
            rec_1->setOutputLocation(QUrl::fromLocalFile("/home/max/song1.amr")); // this is the output location.
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
            QMediaPlaylist *playlist = new QMediaPlaylist();//to assign the voice recorded in rec1() object 
            playlist->addMedia(QUrl::fromLocalFile("/home/max/song1.amr")); //output where the object has to take extract it media from 
            playlist->setPlaybackMode(QMediaPlaylist::Loop); // playing the voice in a loop until the button is pressed
            play_1 = new QMediaPlayer;// assigning playlist as a new media player object player to keep playing and avoiding device conncetion problems 
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
            ui->pushbutton_5->setText("Cats Purr");
            break;
            //
        case QMediaPlayer::PausedState:
        case QMediaPlayer::StoppedState:
            QMediaPlaylist *playlist = new QMediaPlaylist();
            playlist->addMedia(QUrl::fromLocalFile("/home/manush/Documents/yukti/audio_files/Catspurr.mp3"));
            playlist->setPlaybackMode(QMediaPlaylist::Loop);
            play_5 = new QMediaPlayer;
            play_5->setPlaylist(playlist);
            play_5->play();
            ui->pushbutton_5->setText("Cats purr");
            break;
            //
        }
    }
        void playMusic6()
        {
            switch (play_6->state()) {
            case QMediaPlayer::PlayingState:
                play_6->stop();
                ui->pushbutton_6->setText("Leaves");
                break;
                //
            case QMediaPlayer::PausedState:
            case QMediaPlayer::StoppedState:
                QMediaPlaylist *playlist = new QMediaPlaylist();
                playlist->addMedia(QUrl::fromLocalFile("/home/manush/Documents/yukti/audio_files/Leaves.mp3"));
                playlist->setPlaybackMode(QMediaPlaylist::Loop);
                play_6 = new QMediaPlayer;
                play_6->setPlaylist(playlist);
                play_6->play();
                ui->pushbutton_6->setText("Leaves");
                break;
                //
            }
        }

        void playMusic7()
        {
            switch (play_7->state()) {
            case QMediaPlayer::PlayingState:
                play_7->stop();
                ui->pushbutton_7->setText("Snowstorm");
                break;
                //
            case QMediaPlayer::PausedState:
            case QMediaPlayer::StoppedState:
                QMediaPlaylist *playlist = new QMediaPlaylist();
                playlist->addMedia(QUrl::fromLocalFile("/home/manush/Documents/yukti/Final_Submission_ASMR2GO/Software/Sound_processing/Sound_samples/Snowstorm.mp3"));
                playlist->setPlaybackMode(QMediaPlaylist::Loop);
                play_7 = new QMediaPlayer;
                play_7->setPlaylist(playlist);
                play_7->play();
                ui->pushbutton_7->setText("Snowstorm");
                break;
                //
            }
        }
        void playMusic8()
        {
            switch (play_8->state()) {
            case QMediaPlayer::PlayingState:
                play_8->stop();
                ui->pushbutton_7->setText("Pebbles");
                break;
                //
            case QMediaPlayer::PausedState:
            case QMediaPlayer::StoppedState:
                QMediaPlaylist *playlist = new QMediaPlaylist();
                playlist->addMedia(QUrl::fromLocalFile("/home/manush/Documents/yukti/Final_Submission_ASMR2GO/Software/Sound_processing/Sound_samples/Pebbles.mp3"));
                playlist->setPlaybackMode(QMediaPlaylist::Loop);
                play_8 = new QMediaPlayer;
                play_8->setPlaylist(playlist);
                play_8->play();
                ui->pushbutton_8->setText("Pebbles");
                break;
                //
            }
        }

#endif // ASMR2GO_H


