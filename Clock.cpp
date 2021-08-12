//
// Created by alessiorocchi on 21/07/21.
//

#include <ctime>
#include "Clock.h"

wxBEGIN_EVENT_TABLE(Clock, wxPanel)
EVT_TIMER(4, Clock::OnTimer)
wxEND_EVENT_TABLE()


Clock::Clock(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize) {
    mainSizer = new wxBoxSizer(wxVERTICAL);
    panelChioceSizer = new wxBoxSizer(wxHORIZONTAL);

    wxFont font = wxFont(15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

    clockBtn = new wxButton(this, 1, "Clock");
    clockBtn ->SetFont(font);
    clockBtn ->Enable(false);

    timerBtn = new wxButton(this, 2, "Timer");
    timerBtn ->SetFont(font);

    stopwatchBtn = new wxButton(this, 3, "Stopwatch");
    stopwatchBtn ->SetFont(font);

    displayBox = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER | wxBORDER_NONE);
    displayBox ->SetFont(font);

    displayBoxAM_PM = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER | wxBORDER_NONE);
    displayBoxAM_PM ->SetFont(font);

    displayBoxDate = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER | wxBORDER_NONE);
    displayBoxDate ->SetFont(font);

    panelChioceSizer ->Add(clockBtn, 0, wxEXPAND | wxALL , 5);
    panelChioceSizer ->Add(timerBtn, 0, wxEXPAND | wxALL , 5);
    panelChioceSizer ->Add(stopwatchBtn, 0, wxEXPAND | wxALL , 5);

    mainSizer -> Add(panelChioceSizer, 0, wxALIGN_CENTER | wxALL , 0);
    mainSizer -> Add(displayBox, 1, wxEXPAND | wxALL , 5);
    mainSizer -> Add(displayBoxAM_PM, 1, wxEXPAND | wxALL , 5);
    mainSizer -> Add(displayBoxDate, 1, wxEXPAND | wxALL , 5);

    m_timer = new wxTimer(this, 4);
    m_timer -> Start(timerInterval);

    SetSizerAndFit(mainSizer);
    SetAutoLayout(true);
}

Clock::~Clock() {
    delete m_timer;
}

void Clock::display() {
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

    displayBox -> SetValue(time);
    displayBoxAM_PM -> SetValue(timeAM_PM);
    displayBoxDate -> SetValue(date);
}

void Clock::createCurrentTime() {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    hours = now -> tm_hour;
    minutes = now -> tm_min;
    seconds = now -> tm_sec;
    day = now -> tm_mday;
    month = (now -> tm_mon) + 1;
    year = (now -> tm_year) + 1900;
}

void Clock::OnTimer(wxTimerEvent &) {
    createCurrentTime();
    display();
}

