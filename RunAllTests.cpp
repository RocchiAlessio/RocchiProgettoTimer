//
// Created by alessiorocchi on 08/09/21.
//

#include <gtest/gtest.h>
#include <wx/wx.h>

class TestApp: public wxApp{
public:
    virtual bool OnInit();
    virtual int OnRun();
};

bool TestApp::OnInit() {
    return true;
}

int TestApp::OnRun() {
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
}

wxIMPLEMENT_APP(TestApp);