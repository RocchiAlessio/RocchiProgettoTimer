//
// Created by alessiorocchi on 31/07/21.
//

#include "Application.h"

Application::Application() {}

Application::~Application() {}

bool Application::OnInit() {
    frame = new Mframe();
    frame -> Show();
    return true;
}