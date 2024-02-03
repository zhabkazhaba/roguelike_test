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
        Class.cpp
        Item/Item.h
        Item/Item.cpp
        Skill.cpp
        Skill.h
        Item/Artifact.h
        Item/Armor.h
        Item/Armor.cpp
        Item/Artifact.cpp
        Item/Weapon.cpp
        Item/Weapon.h
        Parser.h
        Parser.cpp)
