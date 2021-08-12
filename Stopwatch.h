//
// Created by alessiorocchi on 12/08/21.
//

#ifndef ROCCHIPROGETTOTIMER_STOPWATCH_H
#define ROCCHIPROGETTOTIMER_STOPWATCH_H

#include <wx/wx.h>

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

    static const int timerInterval = 1000;
    wxTimer* m_timer = nullptr;

    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    bool isRunning = false;

    wxDECLARE_EVENT_TABLE();

    void startStopwatch(wxCommandEvent&);

    void OnTimer(wxTimerEvent&);

    void display();

    void clear(wxCommandEvent&);
};


#endif //ROCCHIPROGETTOTIMER_STOPWATCH_H
