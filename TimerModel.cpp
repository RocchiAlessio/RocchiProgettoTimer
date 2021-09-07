//
// Created by alessiorocchi on 07/09/21.
//

#include "TimerModel.h"

TimerModel::TimerModel(wxPanel* parent){
    m_timer = new wxTimer(parent, 9);
}

TimerModel::~TimerModel() {
    delete m_timer;
}



int TimerModel::getSecRemaining() const {
    return secRemaining;
}

void TimerModel::setSecRemaining(int secRemaining) {
    TimerModel::secRemaining = secRemaining;
}

int TimerModel::getMinRemaining() const {
    return minRemaining;
}

void TimerModel::setMinRemaining(int minRemaining) {
    TimerModel::minRemaining = minRemaining;
}

int TimerModel::getHoursRemaining() const {
    return hoursRemaining;
}

void TimerModel::setHoursRemaining(int hoursRemaining) {
    TimerModel::hoursRemaining = hoursRemaining;
}

bool TimerModel::isRunning1() const {
    return isRunning;
}

void TimerModel::setIsRunning(bool isRunning) {
    TimerModel::isRunning = isRunning;
}

const std::string &TimerModel::getRemainingTime() const {
    return remainingTime;
}

void TimerModel::setRemainingTime(const std::string &remainingTime) {
    TimerModel::remainingTime = remainingTime;
}



void TimerModel::createTime() {
    std::string time;
    if(hoursRemaining < 10)
        time = "0" + std::to_string(hoursRemaining);
    else
        time = std::to_string(hoursRemaining);
    time = time + ":";

    if(minRemaining < 10)
        time =  time + "0" + std::to_string(minRemaining);
    else
        time = time + std::to_string(minRemaining);
    time = time + ":";

    if(secRemaining < 10)
        time = time + "0" + std::to_string(secRemaining);
    else
        time = time + std::to_string(secRemaining);

    remainingTime = time;
}

void TimerModel::tick() {
    if(secRemaining == 0 && minRemaining == 0 && hoursRemaining == 0){
        m_timer ->Stop();
        isRunning = false;
    }
    else{
        if(secRemaining == 0 && minRemaining == 0){
            secRemaining = 59;
            minRemaining = 59;
            hoursRemaining --;
        }
        else{
            if(secRemaining == 0 && minRemaining != 0){
                secRemaining = 59;
                minRemaining --;
            }
            else{
                secRemaining--;
            }
        }
    }
}

void TimerModel::start() {
    m_timer->Start(timerInterval);
    isRunning = true;
}

void TimerModel::stop() {
    m_timer ->Stop();
    isRunning = false;
}

