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

    SetSizerAndFit(mainSizer);
    SetAutoLayout(true);

    model = new ClockModel(this);
}

Clock::~Clock() {
    delete model;
}

void Clock::OnTimer(wxTimerEvent &) {
    model ->createCurrentTime();
    model ->createDate();
    displayBox ->SetValue(model->getDates()[0]);
    displayBoxAM_PM ->SetValue(model->getDates()[1]);
    displayBoxDate ->SetValue(model->getDates()[2]);
}

ClockModel *Clock::getModel() const {
    return model;
}
