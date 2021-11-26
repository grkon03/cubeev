
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

cmake_minimum_required(VERSION 3.1)
project(cubeev CXX)
add_executable(cubeev main.cpp evaluator/cevaluator.cpp evaluator/csquares.cpp)
set(CMAKE_CXX_FLAGS "-Wall -g")