//
// Created by alessiorocchi on 13/09/21.
//

#include <gtest/gtest.h>
#include "../ClockModel.h"
#include "../Mframe.h"

class ClockTest : public ::testing::Test {
protected:
    virtual void SetUp();
    virtual void TearDown();

    Mframe* mframe;
    Clock* clock;
};

void ClockTest::SetUp() {
    mframe = new Mframe();
    clock = new Clock(mframe);
}

void ClockTest::TearDown() {
    delete mframe;
}

TEST_F(ClockTest, ChangingHourTest){
    clock->getModel()->getMTimer()->Notify();

    std::string data1 = clock->getModel()->toString(0);

    sleep(1);
    clock->getModel()->getMTimer()->Notify();

    std::string data2 = clock->getModel()->toString(0);

    ASSERT_TRUE(data1.compare(data2) != 0); // == 0 se le stringhe sono uguali
}

TEST_F(ClockTest, ChangingHourAMPMTest) {
    clock->getModel()->getMTimer()->Notify();

    std::string data1 = clock->getModel()->toString(1);

    sleep(1);
    clock->getModel()->getMTimer()->Notify();

    std::string data2 = clock->getModel()->toString(1);

    ASSERT_TRUE(data1.compare(data2) != 0);
}

TEST_F(ClockTest, CorrectVisualizationHour) {
    clock->getModel()->setHours(13);
    clock->getModel()->setMinutes(15);
    clock->getModel()->setSeconds(45);

    clock->getModel()->createDate();

    std::string time =  clock->getModel()->toString(0);

    ASSERT_TRUE(time.compare("13:15:45") == 0);
}

TEST_F(ClockTest, CorrectVisualizationHourAMPM) {
    clock->getModel()->setHours(13);
    clock->getModel()->setMinutes(15);
    clock->getModel()->setSeconds(45);

    clock->getModel()->createDate();

    std::string time =  clock->getModel()->toString(1);

    ASSERT_TRUE(time.compare("PM 01:15:45") == 0);
}

TEST_F(ClockTest, CorrectVisualizationDate) {
    clock->getModel()->setDay(27);
    clock->getModel()->setMonth(5);
    clock->getModel()->setYear(2021);

    clock->getModel()->createDate();

    std::string date =  clock->getModel()->toString(2);

    ASSERT_TRUE(date.compare("27/5/2021") == 0);
}
