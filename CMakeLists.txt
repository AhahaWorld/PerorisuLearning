cmake_minimum_required(VERSION 3.25)
project(PerorisuLearning)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_STANDARD 20)

add_executable(PerorisuLearning define.h pl1.cpp pl2.cpp pl3.cpp pl4.cpp)
target_compile_features(PerorisuLearning PUBLIC cxx_std_20)
