cmake_minimum_required(VERSION 3.30)
project(ChainList)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(ChainList
    src/Log.h
    src/main.cpp)
