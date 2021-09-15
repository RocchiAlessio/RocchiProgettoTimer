//
// Created by alessiorocchi on 21/07/21.
//

#ifndef ROCCHIPROGETTOTIMER_TIMER_H
#define ROCCHIPROGETTOTIMER_TIMER_H

#include <wx/wx.h>
#include "TimerModel.h"

class Timer : public wxPanel{
public:
    Timer(wxWindow* parent);
    virtual ~Timer();

    TimerModel *getModel() const;

    wxDECLARE_EVENT_TABLE();

    void OnTimer(wxTimerEvent&);

    void OnClick(wxCommandEvent&);

private:
    wxBoxSizer* mainSizer = nullptr;
    wxBoxSizer* panelChioceSizer = nullptr;

    wxButton* clockBtn = nullptr;
    wxButton* timerBtn = nullptr;
    wxButton* stopwatchBtn = nullptr;

    wxButton* startBtn = nullptr;
    wxBoxSizer* insertSizer = nullptr;
    wxTextCtrl* hourBox = nullptr;
    wxTextCtrl* separation1 = nullptr;
    wxTextCtrl* minBox = nullptr;
    wxTextCtrl* separation2 = nullptr;
    wxTextCtrl* secBox = nullptr;

    wxTextCtrl* displayBox = nullptr;

    TimerModel* model = nullptr;

};


#endif //ROCCHIPROGETTOTIMER_TIMER_H
