cmake_minimum_required(VERSION 3.22)
project(SBExercise2842)

set(CMAKE_CXX_STANDARD 14)

add_executable(SBExercise2842 src/main.cpp include/Train.h src/Train.cpp include/Station.h src/Station.cpp)

target_include_directories(SBExercise2842 PUBLIC include)
