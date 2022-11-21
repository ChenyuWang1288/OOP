cmake_minimum_required(VERSION 3.22)
project(Assignment02)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment02
        main.cpp
        student.cpp
        student.h)
