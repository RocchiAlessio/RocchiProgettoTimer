//
// Created by alessiorocchi on 07/09/21.
//

#include <ctime>
#include "ClockModel.h"

ClockModel::ClockModel(wxEvtHandler* parent) {
    m_timer = new wxTimer(parent, 4);
    m_timer ->Start(timerInterval);
}

ClockModel::~ClockModel() {
    m_timer ->Stop();
    delete m_timer;
}

void ClockModel::createCurrentTime() {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    hours = now -> tm_hour;
    minutes = now -> tm_min;
    seconds = now -> tm_sec;
    day = now -> tm_mday;
    month = (now -> tm_mon) + 1;
    year = (now -> tm_year) + 1900;
}

std::string ClockModel::toString(int selection = 0) {
    if(selection > 2 || selection < 0)
        return dates[0];
    return dates[selection];
}

void ClockModel::createDate() {
    std::string time;
    std::string timeAM_PM;
    std::string date;

    //trasforma gli int delle ore in una stringa per la visualizzazione
    if(hours < 10)
        time = "0" + std::to_string(hours);
    else
        time = std::to_string(hours);
    time = time + ":";

    if(minutes < 10)
        time =  time + "0" + std::to_string(minutes);
    else
        time = time + std::to_string(minutes);
    time = time + ":";

    if(seconds < 10)
        time = time + "0" + std::to_string(seconds);
    else
        time = time + std::to_string(seconds);

    //fa lo stesso ma per il formato AM/PM
    if(hours < 13) {
        timeAM_PM = "AM ";
        if(hours < 10)
            timeAM_PM = timeAM_PM + "0" + std::to_string(hours);
        else
            timeAM_PM = timeAM_PM + std::to_string(hours);
    }
    else {
        timeAM_PM = "PM ";
        if(hours - 12 < 10)
            timeAM_PM = timeAM_PM + "0" + std::to_string(hours - 12);
        else
            timeAM_PM = timeAM_PM + std::to_string(hours - 12);
    }
    timeAM_PM = timeAM_PM + ":";

    if(minutes < 10)
        timeAM_PM =  timeAM_PM + "0" + std::to_string(minutes);
    else
        timeAM_PM = timeAM_PM + std::to_string(minutes);
    timeAM_PM = timeAM_PM + ":";

    if(seconds < 10)
        timeAM_PM = timeAM_PM + "0" + std::to_string(seconds);
    else
        timeAM_PM = timeAM_PM + std::to_string(seconds);

    //fa la stringa per la data
    date = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);

    dates[0] = time;
    dates[1] = timeAM_PM;
    dates[2] = date;
}

wxTimer *ClockModel::getMTimer() const {
    return m_timer;
}

void ClockModel::setHours(int hours) {
    ClockModel::hours = hours;
}

void ClockModel::setMinutes(int minutes) {
    ClockModel::minutes = minutes;
}

void ClockModel::setSeconds(int seconds) {
    ClockModel::seconds = seconds;
}

void ClockModel::setDay(int day) {
    ClockModel::day = day;
}

void ClockModel::setMonth(int month) {
    ClockModel::month = month;
}

void ClockModel::setYear(int year) {
    ClockModel::year = year;
}
