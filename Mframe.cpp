//
// Created by alessiorocchi on 31/07/21.
//

#include "Mframe.h"

wxBEGIN_EVENT_TABLE(Mframe, wxFrame)
// scelta dal clock
EVT_BUTTON(2, Mframe::buildTimer)
EVT_BUTTON(3, Mframe::buildStopwatch)
// scelta dal timer
EVT_BUTTON(5, Mframe::buildClock)
EVT_BUTTON(7, Mframe::buildStopwatch)
//scelta dallo stopwatch
EVT_BUTTON(10, Mframe::buildClock)
EVT_BUTTON(11, Mframe::buildTimer)
wxEND_EVENT_TABLE()

Mframe::Mframe() : wxFrame(NULL, wxID_ANY, "Clock", wxDefaultPosition, wxSize(330,250)) {
    currentPanel = new Clock(this);
}

Mframe::~Mframe() noexcept {}

void Mframe::buildTimer(wxCommandEvent &) {
    this ->SetTitle("Timer");
    currentPanel -> Destroy();
    currentPanel = new Timer(this);
}

void Mframe::buildClock(wxCommandEvent &) {
    this ->SetTitle("Clock");
    currentPanel -> Destroy();
    currentPanel = new Clock(this);
}

void Mframe::buildStopwatch(wxCommandEvent &) {
    this ->SetTitle("Stopwatch");
    currentPanel -> Destroy();
    currentPanel = new Stopwatch(this);
}