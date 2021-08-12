//
// Created by alessiorocchi on 21/07/21.
//

#ifndef ROCCHIPROGETTOTIMER_TIMER_H
#define ROCCHIPROGETTOTIMER_TIMER_H

#include <wx/wx.h>

class Timer : public wxPanel{
public:
    Timer(wxWindow* parent);
    virtual ~Timer();

private:
    wxBoxSizer* mainSizer = nullptr;
    wxBoxSizer* panelChioceSizer = nullptr;

    wxButton* clockBtn = nullptr;
    wxButton* timerBtn = nullptr;
    wxButton* stopwatchBtn = nullptr;

    wxButton* startBtn = nullptr;
    wxBoxSizer* insertSizer = nullptr;
    wxTextCtrl* hourBox = nullptr;
    wxTextCtrl* minBox = nullptr;
    wxTextCtrl* secBox = nullptr;

    wxTextCtrl* displayBox = nullptr;

    int secRemaining;
    int minRemaining;
    int hoursRemaining;
    bool isRunning = false;

    wxTimer* timer = nullptr;
    static const int timerInterval = 1000;

    wxDECLARE_EVENT_TABLE();

    void OnTimer(wxTimerEvent&);

    void display();

    void OnClick(wxCommandEvent&);
};


#endif //ROCCHIPROGETTOTIMER_TIMER_H
