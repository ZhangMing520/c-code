cmake_minimum_required(VERSION 3.19)
project(ch11)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ch11
        vec.cpp
        vec.h
        vec_test.cpp)

