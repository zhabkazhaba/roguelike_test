cmake_minimum_required(VERSION 3.26)
project(roguelike_test)

set(CMAKE_CXX_STANDARD 14)
set(JSON_BuildTests OFF CACHE INTERNAL "")
include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(roguelike_test
        main.cpp
        src/Actor/Character.h
        src/Game/Map.h
        src/Game/Map.cpp
        src/Actor/Character.cpp
        src/Actor/Class.h
        src/Actor/Class.cpp
        src/Item/Item.h
        src/Item/Item.cpp
        src/Actions/Skill.cpp
        src/Actions/Skill.h
        src/Item/Artifact.h
        src/Item/Armor.h
        src/Item/Armor.cpp
        src/Item/Artifact.cpp
        src/Item/Weapon.cpp
        src/Item/Weapon.h
        src/Utility/Parser.h
        src/Utility/Parser.cpp
        src/Actor/NPC.h
        src/Actor/NPC.cpp
        src/Actor/Actor.h
        src/Actor/Actor.cpp
        src/Game/Game.h
        src/Game/Game.cpp
        src/Actor/Attribute.h
        src/Actor/Attribute.cpp
        src/Game/Cell.h
        src/Game/Cell.cpp
        src/Game/Input.h
        src/Game/Input.cpp
        src/Actions/Actions.h
        src/Actions/Actions.cpp
        src/Actions/ComplexActions.h
        src/Actions/ComplexActions.cpp
        src/Utility/chance.hpp
        src/Utility/constants.h
        src/Utility/jsonMaker/jsonMaker.h
        src/Utility/jsonMaker/jsonMaker.cpp
)

target_link_libraries(roguelike_test PRIVATE nlohmann_json::nlohmann_json)