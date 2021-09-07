//
// Created by alessiorocchi on 12/08/21.
//

#ifndef ROCCHIPROGETTOTIMER_STOPWATCH_H
#define ROCCHIPROGETTOTIMER_STOPWATCH_H

#include <wx/wx.h>
#include "StopwatchModel.h"

class Stopwatch : public wxPanel {
public:
    Stopwatch(wxWindow* parent);
    virtual ~Stopwatch();

private:
    wxBoxSizer* mainSizer = nullptr;
    wxBoxSizer* panelChioceSizer = nullptr;
    wxBoxSizer* controlSizer = nullptr;

    wxButton* timerBtn = nullptr;
    wxButton* clockBtn = nullptr;
    wxButton* stopwatchBtn = nullptr;

    wxButton* startBtn = nullptr;
    wxButton* clearBtn = nullptr;

    wxTextCtrl* displayBox = nullptr;
    wxTextCtrl* displayBoxTimes = nullptr;

    StopwatchModel* model = nullptr;

    wxDECLARE_EVENT_TABLE();

    void startStopwatch(wxCommandEvent&);

    void OnTimer(wxTimerEvent&);

    void clear(wxCommandEvent&);
};


#endif //ROCCHIPROGETTOTIMER_STOPWATCH_H
