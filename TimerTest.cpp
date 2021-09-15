//
// Created by alessiorocchi on 14/09/21.
//

#include <gtest/gtest.h>
#include "../Timer.h"
#include "../Mframe.h"

class TimerTest : public ::testing::Test {
protected:
    virtual void SetUp();
    virtual void TearDown();

    Mframe* mframe;
    Timer* timer;
};

void TimerTest::SetUp() {
    mframe = new Mframe();
    timer = new Timer(mframe);

    timer->getModel()->setHoursRemaining(01);
    timer->getModel()->setMinRemaining(00);
    timer->getModel()->setSecRemaining(00);
}

void TimerTest::TearDown() {
    delete mframe;
}

TEST_F(TimerTest, CorrectTick){
    timer->getModel()->createTime();

    std::string data1 = timer->getModel()->getRemainingTime();

    timer->getModel()->tick();
    timer->getModel()->createTime();

    std::string data2 = timer->getModel()->getRemainingTime();

    ASSERT_TRUE(data1.compare(data2) != 0);
}

TEST_F(TimerTest, CorrectTickValues){
    timer->getModel()->tick();

    timer->getModel()->createTime();
    std::string data = timer->getModel()->getRemainingTime();

    ASSERT_TRUE(data.compare("00:59:59") == 0);
}


