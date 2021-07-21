//
// Created by alessiorocchi on 21/07/21.
//

#ifndef ROCCHIPROGETTOTIMER_TIMER_H
#define ROCCHIPROGETTOTIMER_TIMER_H


class Timer {
private:
    int secRemaining;
    int minRemaining;
    int hoursRemaining;

public:
    Timer(int hour, int min, int sec);
    ~Timer();

    void display();

    void startTimer();
};


#endif //ROCCHIPROGETTOTIMER_TIMER_H
