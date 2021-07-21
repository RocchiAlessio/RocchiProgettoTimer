cmake_minimum_required(VERSION 3.19)
project(RocchiProgettoTimer)

set(CMAKE_CXX_STANDARD 11)

set(wxWidgets_ROOT_DIR </usr/include/wx-3.0-unofficial>)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES main.cpp)
add_executable(Timer ${SOURCE_FILES})

target_link_libraries(Timer ${wxWidgets_LIBRARIES})