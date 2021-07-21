//
// Created by alessiorocchi on 21/07/21.
//

#include <thread>
#include <iostream>
#include "Clock.h"



Clock::Clock() {}

Clock::~Clock() {}

void Clock::startClock() {
    while(true){
        createCurrentTime();
        display();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void Clock::display() {
    std::cout << "ora: " << hours << std::endl ;
    std::cout << "minuti: " << minutes << std::endl;
    std::cout << "secondi: " << seconds << std::endl;
}

void Clock::createCurrentTime() {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    hours = now -> tm_hour;
    minutes = now -> tm_min;
    seconds = now -> tm_sec;
    day = now -> tm_mday;
    month = (now -> tm_mon) + 1;
    year = (now -> tm_year) + 1900;
}

int Clock::getHours() const {
    return hours;
}

void Clock::setHours(int hours) {
    Clock::hours = hours;
}

int Clock::getMinutes() const {
    return minutes;
}

void Clock::setMinutes(int minutes) {
    Clock::minutes = minutes;
}

int Clock::getSeconds() const {
    return seconds;
}

void Clock::setSeconds(int seconds) {
    Clock::seconds = seconds;
}

int Clock::getDay() const {
    return day;
}

void Clock::setDay(int day) {
    Clock::day = day;
}

int Clock::getMonth() const {
    return month;
}

void Clock::setMonth(int month) {
    Clock::month = month;
}

int Clock::getYear() const {
    return year;
}

void Clock::setYear(int year) {
    Clock::year = year;
}
