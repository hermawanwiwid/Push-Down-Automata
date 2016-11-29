cmake_minimum_required(VERSION 3.6)
project(Push_Down_Automata_Versi_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp pushdownautomata.h pushdownautomata.cpp)
add_executable(Push_Down_Automata_Versi_2 ${SOURCE_FILES} pushdownautomata.h)