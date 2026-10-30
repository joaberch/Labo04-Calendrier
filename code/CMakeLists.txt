cmake_minimum_required(VERSION 4.3)
project(code)

set(CMAKE_CXX_STANDARD 20)

add_executable(code main.cpp
        utils.cpp
        utils.h
        display.cpp
        display.h
)
