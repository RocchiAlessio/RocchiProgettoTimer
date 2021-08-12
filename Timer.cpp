//
// Created by alessiorocchi on 21/07/21.
//

#include "Timer.h"

wxBEGIN_EVENT_TABLE(Timer, wxPanel)
EVT_BUTTON(8,Timer::OnClick)
EVT_TIMER(9, Timer::OnTimer)
wxEND_EVENT_TABLE()

Timer::Timer(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize) {
    mainSizer = new wxBoxSizer(wxVERTICAL);
    panelChioceSizer = new wxBoxSizer(wxHORIZONTAL);

    wxFont font = wxFont(15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

    clockBtn = new wxButton(this, 5, "Clock", wxDefaultPosition, wxDefaultSize);
    clockBtn ->SetFont(font);

    timerBtn = new wxButton(this, 6, "Timer", wxDefaultPosition, wxDefaultSize);
    timerBtn ->Enable(false);
    timerBtn ->SetFont(font);

    stopwatchBtn = new wxButton(this, 7, "Stopwatch");
    stopwatchBtn ->SetFont(font);

    insertSizer = new wxBoxSizer(wxHORIZONTAL);
    hourBox = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(100,30), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    hourBox ->SetFont(font);
    minBox = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(100,30), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    minBox ->SetFont(font);
    secBox = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(100,30), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    secBox ->SetFont(font);

    insertSizer ->Add(hourBox, 0, wxEXPAND | wxALL, 5);
    insertSizer ->Add(minBox, 0, wxEXPAND | wxALL, 5);
    insertSizer ->Add(secBox, 0, wxEXPAND | wxALL, 5);

    startBtn = new wxButton(this, 8, "Start", wxDefaultPosition, wxDefaultSize);
    startBtn ->SetFont(font);

    displayBox = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER | wxBORDER_NONE);
    displayBox ->SetFont(font);

    panelChioceSizer->Add(clockBtn, 0, wxEXPAND | wxALL, 5);
    panelChioceSizer->Add(timerBtn, 0, wxEXPAND | wxALL, 5);
    panelChioceSizer->Add(stopwatchBtn, 0, wxEXPAND | wxALL, 5);

    mainSizer ->Add(panelChioceSizer, 0, wxALIGN_CENTER | wxALL, 0);
    mainSizer ->Add(insertSizer, 0, wxALIGN_CENTER | wxALL, 0);
    mainSizer ->Add(startBtn, 0, wxEXPAND | wxALL, 5);
    mainSizer ->Add(displayBox, 1, wxEXPAND | wxALL , 5);

    timer = new wxTimer(this, 9);

    SetSizerAndFit(mainSizer);
    SetAutoLayout(true);
}

Timer::~Timer() {
    delete timer;
}

void Timer::display() {
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

    displayBox -> SetValue(time);
}

void Timer::OnTimer(wxTimerEvent &) {
    if(secRemaining == 0 && minRemaining == 0 && hoursRemaining == 0){
        timer ->Stop();
        startBtn ->SetLabel("Start");
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
    display();
}

void Timer::OnClick(wxCommandEvent&) {
    if(!isRunning){
        isRunning = true;
        secRemaining = wxAtoi(secBox->GetValue());
        minRemaining = wxAtoi(minBox->GetValue());
        hoursRemaining = wxAtoi(hourBox->GetValue());

        startBtn ->SetLabel("Stop");

        timer ->Start(timerInterval);
    }
    else{
        isRunning = false;
        startBtn ->SetLabel("Start");
        timer ->Stop();

    }
}

