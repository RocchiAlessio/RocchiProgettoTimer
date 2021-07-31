//
// Created by alessiorocchi on 21/07/21.
//

#ifndef ROCCHIPROGETTOTIMER_TIMER_H
#define ROCCHIPROGETTOTIMER_TIMER_H

#include <wx/wx.h>

class Timer : public wxPanel{
public:
    Timer(wxWindow* parent);
    ~Timer();

    void display();

    void startTimer();
    void stopTimer();

private:
    int secRemaining;
    int minRemaining;
    int hoursRemaining;
};


#endif //ROCCHIPROGETTOTIMER_TIMER_H
