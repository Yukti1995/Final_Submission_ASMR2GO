#ifndef ASMR_H // Defined by default
#define ASMR_H

#include <QMainWindow>//Library to build main window
#include <QMediaPlayer> //Library to play music
#include <QMediaPlaylist>//Library to interface with other devices
#include <QAudioRecorder> //Library to record music
#include "ui_asmr.h" //header to generate .ui file for home page QT5 wizard generation

namespace Ui {
class ASMR;
}

class ASMR : public QMainWindow // Links the program to the main GUI window 
{
    Q_OBJECT

public:
    explicit ASMR(QWidget *parent = nullptr);
    ~ASMR();

private: //functions can be accessed only inside the class
    Ui::ASMR *ui;
    QAudioRecorder *a_recorder1 = nullptr;
    QAudioRecorder *a_recorder2 = nullptr;
    QAudioRecorder *a_recorder3 = nullptr;
    QAudioRecorder *a_recorder4= nullptr;
    // 4 objects to process live recording on the system 
    QMediaPlayer *m_player1 = nullptr;
    QMediaPlayer *m_player2 = nullptr;
    QMediaPlayer *m_player3 = nullptr;
    QMediaPlayer *m_player4 = nullptr;
    //4 objects to process playing of 4 recorded voices 
    QMediaPlayer *m_player5 = nullptr;
    QMediaPlayer *m_player6= nullptr;
    QMediaPlayer *m_player7= nullptr;
    QMediaPlayer *m_player8 = nullptr;
    // 4 objects to play the pre-recorded voices 
    //my main functions()

private slots:
    void recordMusic1() // main function 1
    {
        switch (a_recorder1->state()) {
        case QAudioRecorder::RecordingState: // if the current state of the recorder function is already recording, this would stop it and 
                //break it out of the loop
            a_recorder1->stop();
            break;
          
        case QAudioRecorder::PausedState://when the current state of recorder is paused, it is allowed to go in the stopped state and 
                //with an adaptive Multi Rate format the object rec_1 on pushing it starts to record 
        case QAudioRecorder::StoppedState:
            QAudioEncoderSettings audioSettings;
            audioSettings.setCodec("audio/amr");// amr , audio compression format for live speech signals 
            audioSettings.setQuality(QMultimedia::HighQuality);
            a_recorder1->setEncodingSettings(audioSettings);
            a_recorder1->setOutputLocation(QUrl::fromLocalFile("/home/max/song1.amr")); // this is the output location.
            a_recorder1->record();
            break;
            //
        }
    }
    void recordMusic2()
    {
        switch (a_recorder2->state()) {
        case QAudioRecorder::RecordingState:
            a_recorder2->stop();
            break;
            //
        case QAudioRecorder::PausedState:
        case QAudioRecorder::StoppedState:
            QAudioEncoderSettings audioSettings;
            audioSettings.setCodec("audio/amr");
            audioSettings.setQuality(QMultimedia::HighQuality);
            a_recorder2->setEncodingSettings(audioSettings);
            a_recorder2->setOutputLocation(QUrl::fromLocalFile("/home/max/song2.amr"));
            a_recorder2->record();
            break;
            //
        }
    }
    void recordMusic3()
    {
        switch (a_recorder3->state()) {
        case QAudioRecorder::RecordingState:
            a_recorder3->stop();
            break;
            //
        case QAudioRecorder::PausedState:
        case QAudioRecorder::StoppedState:
            QAudioEncoderSettings audioSettings;
            audioSettings.setCodec("audio/amr");
            audioSettings.setQuality(QMultimedia::HighQuality);
            a_recorder3->setEncodingSettings(audioSettings);
            a_recorder3->setOutputLocation(QUrl::fromLocalFile("/home/max/song3.amr"));
            a_recorder3->record();
            break;
            //
        }
    }
    void recordMusic4()
    {
        switch (a_recorder4->state()) {
        case QAudioRecorder::RecordingState:
            a_recorder4->stop();
            break;
            //
        case QAudioRecorder::PausedState:
        case QAudioRecorder::StoppedState:
            QAudioEncoderSettings audioSettings;
            audioSettings.setCodec("audio/amr");
            audioSettings.setQuality(QMultimedia::HighQuality);
            a_recorder4->setEncodingSettings(audioSettings);
            a_recorder4->setOutputLocation(QUrl::fromLocalFile("/home/max/song4.amr"));
            a_recorder4->record();
            break;
            //
        }
    }



    void playMusic1()
    {
        switch (m_player1->state()) {
        case QMediaPlayer::PlayingState:
            m_player1->stop();
            ui->pushbutton_1->setText("");
            break;
            //
        case QMediaPlayer::PausedState:
        case QMediaPlayer::StoppedState:
            QMediaPlaylist *playlist = new QMediaPlaylist();//to assign the voice recorded in rec1() object 
            playlist->addMedia(QUrl::fromLocalFile("/home/max/song1.amr")); //output where the object has to take extract it media from 
            playlist->setPlaybackMode(QMediaPlaylist::Loop); // playing the voice in a loop until the button is pressed
            m_player1 = new QMediaPlayer;// assigning playlist as a new media player object player to keep playing and avoiding device conncetion problems 
            m_player1->setPlaylist(playlist);
            ui->pushbutton_1->setText("...");
            play_1->play();
            break;
            //
        }
    }

    void playMusic2()
    {
        switch (m_player2->state()) {
        case QMediaPlayer::PlayingState:
            m_player2->stop();
            ui->pushbutton_2->setText("");
            break;
            //
        case QMediaPlayer::PausedState:
        case QMediaPlayer::StoppedState:
            QMediaPlaylist *playlist = new QMediaPlaylist();
            playlist->addMedia(QUrl::fromLocalFile("/home/max/song2.amr"));
            playlist->setPlaybackMode(QMediaPlaylist::Loop);
            m_player2 = new QMediaPlayer;
            m_player2->setPlaylist(playlist);
            ui->pushbutton_2->setText("...");
            m_player2->play();
            break;
            //
        }
    }

      void playMusic3()
    {
        switch (m_player3->state()) {
        case QMediaPlayer::PlayingState:
            m_player3->stop();
            ui->pushbutton_3->setText("");
            break;
            //
        case QMediaPlayer::PausedState:
        case QMediaPlayer::StoppedState:
            QMediaPlaylist *playlist = new QMediaPlaylist();
            playlist->addMedia(QUrl::fromLocalFile("/home/max/song3.amr"));
            playlist->setPlaybackMode(QMediaPlaylist::Loop);
            m_player3= new QMediaPlayer;
            m_player3->setPlaylist(playlist);
            m_player3->play();
            ui->pushbutton_3->setText("...");
            break;
            //
        }
    }

    void playMusic4()
    {
        switch (m_player4->state()) {
        case QMediaPlayer::PlayingState:
            m_player4->stop();
            ui->pushbutton_4->setText("");
            break;
            //
        case QMediaPlayer::PausedState:
        case QMediaPlayer::StoppedState:
            QMediaPlaylist *playlist = new QMediaPlaylist();
            playlist->addMedia(QUrl::fromLocalFile("/home/max/song4.amr"));
            playlist->setPlaybackMode(QMediaPlaylist::Loop);
            m_player4 = new QMediaPlayer;
            m_player4->setPlaylist(playlist);
            m_player4->play();
            ui->pushbutton_4->setText("...");
            break;
            //
        }

    }
    void playMusic5()
    {
        switch (m_player5->state()) {
        case QMediaPlayer::PlayingState:
            m_player3->stop();
            ui->pushbutton_5->setText("1");
            break;
            //
        case QMediaPlayer::PausedState:
        case QMediaPlayer::StoppedState:
            QMediaPlaylist *playlist = new QMediaPlaylist();
            playlist->addMedia(QUrl::fromLocalFile("/home/manush/Documents/yukti/audio_files/Catspurr.mp3"));
            playlist->setPlaybackMode(QMediaPlaylist::Loop);
            m_player5 = new QMediaPlayer;
            m_player5->setPlaylist(playlist);
            m_player5->play();
            ui->pushbutton_5->setText("Cats purr");
            break;
            //
        }
    }
        void playMusic6()
        {
            switch (m_player6->state()) {
            case QMediaPlayer::PlayingState:
                m_player6->stop();
                ui->pushbutton_6->setText("2");
                break;
                //
            case QMediaPlayer::PausedState:
            case QMediaPlayer::StoppedState:
                QMediaPlaylist *playlist = new QMediaPlaylist();
                playlist->addMedia(QUrl::fromLocalFile("/home/manush/Documents/yukti/audio_files/Leaves.mp3"));
                playlist->setPlaybackMode(QMediaPlaylist::Loop);
                m_player6 = new QMediaPlayer;
                m_player6->setPlaylist(playlist);
                m_player6->play();
                ui->pushbutton_6->setText("Leaves");
                break;
                //
            }
        }

        void playMusic7()
        {
            switch (m_player7->state()) {
            case QMediaPlayer::PlayingState:
                m_player7->stop();
                ui->pushbutton_7->setText("3");
                break;
                //
            case QMediaPlayer::PausedState:
            case QMediaPlayer::StoppedState:
                QMediaPlaylist *playlist = new QMediaPlaylist();
                playlist->addMedia(QUrl::fromLocalFile("/home/manush/Documents/yukti/Final_Submission_ASMR2GO/Software/Sound_processing/Sound_samples/Snowstorm.mp3"));
                playlist->setPlaybackMode(QMediaPlaylist::Loop);
                m_player7= new QMediaPlayer;
                m_player7->setPlaylist(playlist);
                m_player7->play();
                ui->pushbutton_7->setText("Snowstorm");
                break;
                //
            }
        }
        void playMusic8()
        {
            switch (m_player8->state()) {
            case QMediaPlayer::PlayingState:
                m_player8->stop();
                ui->pushbutton_7->setText("4");
                break;
                //
            case QMediaPlayer::PausedState:
            case QMediaPlayer::StoppedState:
                QMediaPlaylist *playlist = new QMediaPlaylist();
                playlist->addMedia(QUrl::fromLocalFile("/home/manush/Documents/yukti/Final_Submission_ASMR2GO/Software/Sound_processing/Sound_samples/Pebbles.mp3"));
                playlist->setPlaybackMode(QMediaPlaylist::Loop);
                m_player8 = new QMediaPlayer;
                m_player8->setPlaylist(playlist);
                m_player8->play();
                ui->pushbutton_8->setText("Pebbles");
                break;
                //
            }
        }

#endif // ASMR_H


