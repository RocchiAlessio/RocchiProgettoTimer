//
// Created by alessiorocchi on 13/09/21.
//

#include <gtest/gtest.h>
#include <thread>
#include "../ClockModel.h"

TEST(ClockTest, ChangingHourTest){
    wxEvtHandler* handler = new wxEvtHandler();
    ClockModel* clockModel = new ClockModel(handler);

    clockModel->createCurrentTime();
    clockModel->createDate();
    std::string data1 = clockModel->getDates()[0];
    data1 = clockModel->getDates()[0];

    sleep(1);

    clockModel->createCurrentTime();
    clockModel->createDate();
    std::string data2 = clockModel->getDates()[0];

    ASSERT_NE(data1, data2);
}

TEST(ClockTest, ChangingHourAMPMTest){
    wxEvtHandler* handler = new wxEvtHandler();
    ClockModel* clockModel = new ClockModel(handler);

    clockModel->createCurrentTime();
    clockModel->createDate();
    std::string data1 = clockModel->getDates()[1];
    data1 = clockModel->getDates()[0];

    sleep(1);

    clockModel->createCurrentTime();
    clockModel->createDate();
    std::string data2 = clockModel->getDates()[1];

    ASSERT_NE(data1, data2);
}
