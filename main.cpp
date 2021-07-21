#include <wx/wx.h>
#include "Clock.h"
#include "Timer.h"

int main(){
    Timer *c = new Timer(0,0,1343);
    c -> startTimer();
}