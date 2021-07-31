//
// Created by alessiorocchi on 31/07/21.
//

#ifndef ROCCHIPROGETTOTIMER_APPLICATION_H
#define ROCCHIPROGETTOTIMER_APPLICATION_H


#include <wx/wx.h>
#include "Mframe.h"

class Application : public wxApp{
public:
    Application();
    virtual ~Application();

    bool OnInit();

private:
    Mframe* frame = nullptr;
};

#endif //ROCCHIPROGETTOTIMER_APPLICATION_H
