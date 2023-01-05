cmake_minimum_required(VERSION 3.24)
project(ProjectBengkelV2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ProjectBengkelV2
        main.cpp
        menu.cpp
        menu.h)
