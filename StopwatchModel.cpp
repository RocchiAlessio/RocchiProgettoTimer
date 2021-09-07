//
// Created by alessiorocchi on 07/09/21.
//

#include "StopwatchModel.h"

StopwatchModel::StopwatchModel(wxPanel* parent) {
    m_timer = new wxTimer(parent, 14);
}

StopwatchModel::~StopwatchModel() {
    delete m_timer;
}

void StopwatchModel::start() {
    m_timer->Start(timerInterval);
    isRunning = true;
}

void StopwatchModel::stop() {
    m_timer->Stop();
    isRunning = false;
}


void StopwatchModel::makeTime() {
    std::string time;

    if(hours < 10)
        time = "0" + std::to_string(hours);
    else
        time = std::to_string(hours);
    time = time + ":";

    if(minutes < 10)
        time = time + "0" + std::to_string(minutes);
    else
        time = time + std::to_string(minutes);
    time = time + ":";

    if(seconds < 10)
        time = time + "0" + std::to_string(seconds);
    else
        time = time + std::to_string(seconds);
    time = time + ",";

    if(hundredths < 10)
        time = time + "0" + std::to_string(hundredths);
    else
        time = time + std::to_string(hundredths);

    actualTime = time;
}

void StopwatchModel::tick() {
    if(minutes == 59 && seconds == 59 && hundredths == 99){
        hours++;
        minutes = 0;
        seconds = 0;
        hundredths = 0;
    }
    else{
        if(seconds == 59 && hundredths == 99){
            minutes++;
            seconds = 0;
            hundredths = 0;
        }
        else{
            if(hundredths == 99){
                seconds++;
                hundredths = 0;
            }
            else
                hundredths++;
        }
    }
}

void StopwatchModel::reset() {
    if(isRunning){
        isRunning = false;
        m_timer -> Stop();
    }
    hours = 0;
    minutes = 0;
    seconds = 0;
    hundredths = 0;
    actualTime = "00:00:00,00";
}

bool StopwatchModel::isRunning1() const {
    return isRunning;
}

const std::string &StopwatchModel::getActualTime() const {
    return actualTime;
}
