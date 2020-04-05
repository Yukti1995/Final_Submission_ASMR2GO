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
