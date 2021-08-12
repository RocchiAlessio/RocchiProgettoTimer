//
// Created by alessiorocchi on 31/07/21.
//

#ifndef ROCCHIPROGETTOTIMER_MFRAME_H
#define ROCCHIPROGETTOTIMER_MFRAME_H

#include <wx/wx.h>
#include "Clock.h"
#include "Timer.h"
#include "Stopwatch.h"

class Mframe : public wxFrame{
public:
    Mframe();
    virtual ~Mframe();

    wxDECLARE_EVENT_TABLE();

private:
    wxPanel* currentPanel = nullptr;

    void buildTimer(wxCommandEvent&);

    void buildClock(wxCommandEvent&);

    void buildStopwatch(wxCommandEvent&);
};


#endif //ROCCHIPROGETTOTIMER_MFRAME_H
