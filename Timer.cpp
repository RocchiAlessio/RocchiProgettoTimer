//
// Created by alessiorocchi on 21/07/21.
//

#include "Timer.h"

Timer::Timer(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize) {

}

Timer::~Timer() {}

void Timer::display() {
    std::cout << "tempo rimasto:" << std::endl << hoursRemaining << ":" ;
    std::cout << minRemaining << ":";
    std::cout << secRemaining << std::endl;
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
    }
}
