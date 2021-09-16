project(Test)

set(wxWidgets_ROOT_DIR </usr/include/wx-3.0-unofficial>)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_subdirectory(./lib/googletest-master)
set(gtest_SOURCE_DIR, ./lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES RunAllTests.cpp ClockTests.cpp TimerTest.cpp StopwatchTest.cpp)
add_executable(runAppTest ${TEST_SOURCE_FILES})
target_link_libraries(runAppTest gtest gtest_main core ${wxWidgets_LIBRARIES})