//
// Created by alessiorocchi on 31/07/21.
//

#include "Mframe.h"

wxBEGIN_EVENT_TABLE(Mframe, wxFrame)
EVT_BUTTON(2, Mframe::buildTimer)
wxEND_EVENT_TABLE()

Mframe::Mframe() : wxFrame(NULL, wxID_ANY, "Timer", wxDefaultPosition, wxSize(500,300)) {
    currentPanel = new Clock(this);
}

Mframe::~Mframe() noexcept {}

void Mframe::buildTimer(wxCommandEvent &) {
    //TODO fix the change panel events
    //currentPanel -> Destroy();
    //currentPanel = new Timer(this);
}
