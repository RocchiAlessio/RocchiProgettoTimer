//
// Created by alessiorocchi on 15/09/21.
//

#include <gtest/gtest.h>
#include "../Stopwatch.h"
#include "../Mframe.h"

class StopwatchTest : public ::testing::Test {
protected:
    virtual void SetUp();
    virtual void TearDown();

    Mframe* mframe;
    Stopwatch* stopwatch;
};

void StopwatchTest::SetUp() {
    mframe = new Mframe();
    stopwatch = new Stopwatch(mframe);
}

void StopwatchTest::TearDown() {
    delete mframe;
}

TEST_F(StopwatchTest, CorrectTick) {
    for(int i=0; i<100; i++)
        stopwatch->getModel()->tick();

    stopwatch->getModel()->makeTime();
    std::string data = stopwatch->getModel()->getActualTime();

    ASSERT_TRUE(data.compare("00:00:01,00") == 0 );
}

TEST_F(StopwatchTest, CorrectReset) {
    for(int i=0; i<100; i++)
        stopwatch->getModel()->tick();

    stopwatch->getModel()->reset();
    stopwatch->getModel()->makeTime();

    std::string data = stopwatch->getModel()->getActualTime();

    ASSERT_TRUE(data.compare("00:00:00,00") == 0 );
}

TEST_F(StopwatchTest, CorrectStart){
    stopwatch->getModel()->start();

    bool flag = stopwatch->getModel()->isRunning1();
    ASSERT_TRUE(flag);
}

TEST_F(StopwatchTest, CorrectStop){
    stopwatch->getModel()->start();
    stopwatch->getModel()->stop();

    bool flag = stopwatch->getModel()->isRunning1();
    ASSERT_TRUE(!flag);
}