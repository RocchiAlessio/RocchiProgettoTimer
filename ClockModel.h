//
// Created by alessiorocchi on 07/09/21.
//

#ifndef ROCCHIPROGETTOTIMER_CLOCKMODEL_H
#define ROCCHIPROGETTOTIMER_CLOCKMODEL_H


#include <wx/wx.h>

class ClockModel{
public:
    ClockModel(wxPanel* parent);
    virtual ~ClockModel();

    void createDate();

    void createCurrentTime();

    const std::string *getDates() const;

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
