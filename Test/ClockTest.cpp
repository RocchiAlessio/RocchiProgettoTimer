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
