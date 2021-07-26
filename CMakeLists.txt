cmake_minimum_required(VERSION 3.19)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Unit00)
include_directories(Unit01)

add_executable(DSA
        Unit01/HailStones.cpp
        Unit01/HailStones.h
        main.cpp
        Unit00/chapter13/TableTennisPlayer.cpp Unit00/chapter13/TableTennisPlayer.h Unit00/chapter13/RatePlayer.cpp Unit00/chapter13/RatePlayer.h Unit00/chapter13/BrassPlus.cpp Unit00/chapter13/BrassPlus.h)
