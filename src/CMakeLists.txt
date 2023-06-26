cmake_minimum_required(VERSION 3.22)

add_executable(correct_string main.cpp ${MY_INCLUDE_DIR}/myWindow.h myWindow.cpp)

target_include_directories(correct_string PRIVATE ${MY_INCLUDE_DIR})
