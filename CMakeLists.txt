cmake_minimum_required(VERSION 3.26)
project(roguelike_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(roguelike_test
        main.cpp
        Character.h
        Map.h
        Map.cpp
        Character.cpp
        Class.h
        Class.cpp)
