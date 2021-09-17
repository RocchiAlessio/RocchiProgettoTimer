//
// Created by alessiorocchi on 07/09/21.
//

#ifndef ROCCHIPROGETTOTIMER_CLOCKMODEL_H
#define ROCCHIPROGETTOTIMER_CLOCKMODEL_H


#include <wx/wx.h>

class ClockModel{
public:
    ClockModel(wxEvtHandler* parent);
    virtual ~ClockModel();

    void createDate();

    std::string toString(int selection);

    void createCurrentTime();

    wxTimer *getMTimer() const;

    void setHours(int hours);

    void setMinutes(int minutes);

    void setSeconds(int seconds);

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

private:
    static const int timerInterval = 1000;
    wxTimer* m_timer = nullptr;

    int hours;
    int minutes;
    int seconds;
    int day;
    int month;
    int year;

    std::string dates[3];
};


#endif //ROCCHIPROGETTOTIMER_CLOCKMODEL_H
