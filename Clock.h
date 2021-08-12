//
// Created by alessiorocchi on 21/07/21.
//

#ifndef ROCCHIPROGETTOTIMER_CLOCK_H
#define ROCCHIPROGETTOTIMER_CLOCK_H

#include <wx/wx.h>

class Clock : public wxPanel {
public:
    Clock(wxWindow* parent);
    virtual ~Clock();

wxDECLARE_EVENT_TABLE();

private:
    wxBoxSizer* mainSizer = nullptr;
    wxBoxSizer* panelChioceSizer = nullptr;

    wxButton* timerBtn = nullptr;
    wxButton* clockBtn = nullptr;
    wxButton* stopwatchBtn = nullptr;

    wxTextCtrl* displayBox = nullptr;
    wxTextCtrl* displayBoxAM_PM = nullptr;
    wxTextCtrl* displayBoxDate = nullptr;

    static const int timerInterval = 1000;
    wxTimer* m_timer = nullptr;

    int hours;
    int minutes;
    int seconds;
    int day;
    int month;
    int year;

    void createCurrentTime();

    void display();

    void OnTimer(wxTimerEvent&);


};


#endif //ROCCHIPROGETTOTIMER_CLOCK_H
