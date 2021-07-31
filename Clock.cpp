//
// Created by alessiorocchi on 21/07/21.
//

#include <ctime>
#include "Clock.h"

wxBEGIN_EVENT_TABLE(Clock, wxPanel)
EVT_TIMER(3, Clock::OnTimer)
wxEND_EVENT_TABLE()


Clock::Clock(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize) {
    mainSizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(mainSizer);
    SetAutoLayout(true);
    panelChioceSizer = new wxBoxSizer(wxHORIZONTAL);

    wxFont font = wxFont(15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

    clockBtn = new wxButton(this, 1, "Clock");
    clockBtn ->SetFont(font);
    clockBtn ->Enable(false);

    timerBtn = new wxButton(this, 2, "Timer");
    timerBtn ->SetFont(font);

    displayBox = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH2 );
    displayBox ->SetFont(font);
    wxLog::SetActiveTarget(new wxLogTextCtrl(displayBox));

    panelChioceSizer ->Add(timerBtn, 0, wxEXPAND | wxALL , 5);
    panelChioceSizer ->Add(clockBtn, 0, wxEXPAND | wxALL , 5);

    mainSizer -> Add(panelChioceSizer, 0, wxALIGN_CENTER | wxALL , 0);
    mainSizer -> Add(displayBox, 1, wxEXPAND | wxALL , 5);

    m_timer = new wxTimer(this, 3);
    m_timer -> Start(timerInterval);
}

Clock::~Clock() {}

void Clock::display() {
    std::string time;
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

    displayBox -> SetValue(time);
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
