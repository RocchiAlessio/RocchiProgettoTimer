//
// Created by alessiorocchi on 12/08/21.
//

#include "Stopwatch.h"

BEGIN_EVENT_TABLE(Stopwatch, wxPanel)
EVT_BUTTON(12, Stopwatch::startStopwatch)
EVT_BUTTON(13, Stopwatch::clear)
EVT_TIMER(14, Stopwatch::OnTimer)
END_EVENT_TABLE()

Stopwatch::Stopwatch(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize){
    mainSizer = new wxBoxSizer(wxVERTICAL);
    panelChioceSizer = new wxBoxSizer(wxHORIZONTAL);
    controlSizer = new wxBoxSizer(wxHORIZONTAL);

    wxFont font = wxFont(15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

    clockBtn = new wxButton(this, 10, "Clock");
    clockBtn ->SetFont(font);

    timerBtn = new wxButton(this, 11, "Timer");
    timerBtn ->SetFont(font);

    stopwatchBtn = new wxButton(this, 12, "Stopwatch");
    stopwatchBtn ->SetFont(font);
    stopwatchBtn ->Enable(false);

    startBtn = new wxButton(this, 12, "Start");
    startBtn ->SetFont(font);

    clearBtn = new wxButton(this, 13, "Reset");
    clearBtn ->SetFont(font);

    displayBox = new wxTextCtrl(this, wxID_ANY, "00:00:00,00", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER | wxBORDER_NONE);
    displayBox ->SetFont(font);

    panelChioceSizer ->Add(clockBtn, 0, wxEXPAND | wxALL , 5);
    panelChioceSizer ->Add(timerBtn, 0, wxEXPAND | wxALL , 5);
    panelChioceSizer ->Add(stopwatchBtn, 0, wxEXPAND | wxALL , 5);

    controlSizer ->Add(startBtn, 0, wxEXPAND | wxALL, 5);
    controlSizer ->Add(clearBtn, 0, wxEXPAND | wxALL, 5);

    mainSizer ->Add(panelChioceSizer, 0, wxALIGN_CENTER | wxALL, 0);
    mainSizer ->Add(controlSizer, 0, wxALIGN_CENTER | wxALL, 0);
    mainSizer ->Add(displayBox, 1, wxEXPAND | wxALL, 5);

    model = new StopwatchModel(this);

    SetSizerAndFit(mainSizer);
    SetAutoLayout(true);
}

Stopwatch::~Stopwatch(){
}

void Stopwatch::startStopwatch(wxCommandEvent &) {
    if(!model->isRunning1()){
        model->start();
        startBtn->SetLabel("Stop");
    }
    else{
        model->stop();
        startBtn->SetLabel("Start");
    }
}

void Stopwatch::OnTimer(wxTimerEvent &) {
    model->tick();
    model->makeTime();
    std::string time = model->getActualTime();
    displayBox->SetValue(time);
}

void Stopwatch::clear(wxCommandEvent&) {
    model->reset();
    std::string time = model->getActualTime();
    displayBox->SetValue(time);
}

StopwatchModel *Stopwatch::getModel() const {
    return model;
}
