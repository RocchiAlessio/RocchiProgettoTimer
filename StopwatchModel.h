//
// Created by alessiorocchi on 07/09/21.
//

#ifndef ROCCHIPROGETTOTIMER_STOPWATCHMODEL_H
#define ROCCHIPROGETTOTIMER_STOPWATCHMODEL_H


#include <wx/wx.h>

class StopwatchModel {
public:
    StopwatchModel(wxPanel* parent);
    virtual ~StopwatchModel();

    void start();

    void stop();

    void makeTime();

    void tick();

    void reset();

    bool isRunning1() const;
    const std::string &getActualTime() const;

private:
    static const int timerInterval = 10;
    wxTimer* m_timer = nullptr;

    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int hundredths = 0;
    bool isRunning = false;
    std::string actualTime = "00:00:00,00";
};


#endif //ROCCHIPROGETTOTIMER_STOPWATCHMODEL_H
