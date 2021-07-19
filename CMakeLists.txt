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
        )
