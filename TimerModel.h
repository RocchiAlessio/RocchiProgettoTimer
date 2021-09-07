//
// Created by alessiorocchi on 07/09/21.
//

#ifndef ROCCHIPROGETTOTIMER_TIMERMODEL_H
#define ROCCHIPROGETTOTIMER_TIMERMODEL_H


#include <wx/wx.h>

class TimerModel {
public:
    TimerModel(wxPanel* parent);
    virtual ~TimerModel();

    int getSecRemaining() const;

    void setSecRemaining(int secRemaining);

    int getMinRemaining() const;

    void setMinRemaining(int minRemaining);

    int getHoursRemaining() const;

    void setHoursRemaining(int hoursRemaining);

    bool isRunning1() const;

    void setIsRunning(bool isRunning);

    const std::string &getRemainingTime() const;

    void setRemainingTime(const std::string &remainingTime);


    void createTime();
    void tick();

    void start();
    void stop();

private:
    int secRemaining;
    int minRemaining;
    int hoursRemaining;
    bool isRunning = false;

    std::string remainingTime;

    wxTimer* m_timer = nullptr;
    static const int timerInterval = 1000;
};


#endif //ROCCHIPROGETTOTIMER_TIMERMODEL_H
