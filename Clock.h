//
// Created by alessiorocchi on 21/07/21.
//

#ifndef ROCCHIPROGETTOTIMER_CLOCK_H
#define ROCCHIPROGETTOTIMER_CLOCK_H


class Clock {
private:
    int hours;
    int minutes;
    int seconds;
    int day;
    int month;
    int year;

    void createCurrentTime();

    void display();

public:
    Clock();

    ~Clock();

    void startClock();

    int getHours() const;
    void setHours(int hours);

    int getMinutes() const;
    void setMinutes(int minutes);

    int getSeconds() const;
    void setSeconds(int seconds);

    int getDay() const;
    void setDay(int day);

    int getMonth() const;
    void setMonth(int month);

    int getYear() const;
    void setYear(int year);

};


#endif //ROCCHIPROGETTOTIMER_CLOCK_H
