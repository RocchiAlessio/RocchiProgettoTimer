//
// Created by alessiorocchi on 21/07/21.
//

#include <iostream>
#include <thread>
#include "Timer.h"

Timer::Timer(int hour, int min, int sec) {
    hoursRemaining = hour;
    minRemaining = min;
    secRemaining = sec;
}

Timer::~Timer() {}

void Timer::display() {
    std::cout << "ora: " << hoursRemaining << std::endl ;
    std::cout << "minuti: " << minRemaining << std::endl;
    std::cout << "secondi: " << secRemaining << std::endl;
}

void Timer::startTimer() {
    while(hoursRemaining != 0 || minRemaining != 0 || secRemaining != 0){
        if(secRemaining > 0)
            secRemaining--;
        else{
            if(minRemaining > 0){
                minRemaining--;
                secRemaining = 59;
            }
            else{
                if(hoursRemaining > 0){
                    hoursRemaining--;
                    minRemaining = 59;
                    secRemaining = 59;
                }
            }
        }
        display();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
