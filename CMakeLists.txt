cmake_minimum_required(VERSION 3.26)
project(roguelike_test)

set(CMAKE_CXX_STANDARD 14)
set(JSON_BuildTests OFF CACHE INTERNAL "")
include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(roguelike_test
        main.cpp
        Actor/Character.h
        Game/Map.h
        Game/Map.cpp
        Actor/Character.cpp
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
        Parser.cpp
        Actor/NPC.h
        Actor/NPC.cpp
        Actor/Actor.h
        Actor/Actor.cpp
        Game/Game.h
        Game/Game.cpp
        Actor/Attribute.h
        Actor/Attribute.cpp
        Game/Cell.h
        Game/Cell.cpp
        Game/Input.h
        Game/Input.cpp
        Game/Actions.h
        Game/Actions.cpp
        Game/ComplexActions.h
        Game/ComplexActions.cpp
        Utility/chance.hpp
        Utility/constants.h
)

target_link_libraries(roguelike_test PRIVATE nlohmann_json::nlohmann_json)