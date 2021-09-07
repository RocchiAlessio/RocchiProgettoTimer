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
    hourBox = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(80,30), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    hourBox ->SetFont(font);
    separation1 = new wxTextCtrl(this, wxID_ANY, ":", wxDefaultPosition, wxSize(30,30), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER | wxTE_READONLY | wxBORDER_NONE);
    separation1 ->SetFont(font);
    minBox = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(80,30), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    minBox ->SetFont(font);
    separation2 = new wxTextCtrl(this, wxID_ANY, ":", wxDefaultPosition, wxSize(30,30), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER | wxTE_READONLY | wxBORDER_NONE);
    separation2 ->SetFont(font);
    secBox = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(80,30), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    secBox ->SetFont(font);

    insertSizer ->Add(hourBox, 0, wxEXPAND | wxALL, 5);
    insertSizer ->Add(separation1, 0, wxEXPAND | wxALL, 0);
    insertSizer ->Add(minBox, 0, wxEXPAND | wxALL, 5);
    insertSizer ->Add(separation2,  0, wxEXPAND | wxALL, 0);
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

    model = new TimerModel(this);

    SetSizerAndFit(mainSizer);
    SetAutoLayout(true);
}

Timer::~Timer() {
    delete model;
}

void Timer::OnClick(wxCommandEvent&) {
    if(!model->isRunning1()){
        model->setIsRunning(true);
        model->setSecRemaining(wxAtoi(secBox->GetValue()));
        model->setMinRemaining(wxAtoi(minBox->GetValue()));
        model->setHoursRemaining(wxAtoi(hourBox->GetValue()));

        secBox -> SetValue("00");
        minBox -> SetValue("00");
        hourBox -> SetValue("00");

        startBtn ->SetLabel("Stop");

        model->start();
    }
    else{
        model -> setIsRunning(false);
        startBtn ->SetLabel("Start");
        model -> stop();
    }
}

void Timer::OnTimer(wxTimerEvent &) {
    model ->tick();
    model ->createTime();
    if(model->isRunning1() && model->getRemainingTime() == "00:00:00")
        startBtn ->SetLabel("Start");
    std::string time = model->getRemainingTime();
    displayBox->SetValue(time);
}
