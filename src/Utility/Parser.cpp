#include <iostream>
#include "Parser.h"
#include "nlohmann/json.hpp"

Parser::Parser() {
    mode = readMode::NPC;
    filename = "dump";
}

Parser::Parser(readMode init_mode, const std::string &init_file) {
    mode = init_mode;
    filename = init_file;
}

Parser::Parser(Parser &o) {
    mode = o.mode;
    filename = o.filename;
}

Parser::~Parser() {
    file.is_open()  ? file.close() : file.clear();
}

void Parser::closeFile() {
    if (file.is_open())
        file.close();
}

void Parser::setFilename(const std::string &input) {
    filename = input;
}

void Parser::openFileIn(const std::string &input) {
    if (file.is_open())
        file.close();
    if (input.empty()) {
        std::string temp = filename + ".json";
        file.open(temp, std::ios::in);
    }
    else {
        std::string temp = input + ".json";
        file.open(temp, std::ios::in);
    }
}

void Parser::parse() {
    if (!file.is_open())
        openFileIn();
    switch (mode) {
        case readMode::NPC:
            parseNPC();
            break;
        case readMode::CLASS:
            parseClass();
            break;
        case readMode::ABILITY:
            //parseAbility();
            break;
        case readMode::WEAPON:
            parseWeapon();
            break;
        default:
            std::cerr << "jsonParser Error: Invalid mode!" << std::endl;
    }
}

Parser::NPC_tuple Parser::parseNPC() {
    if (!file.is_open())
        openFileIn();
    nlohmann::json j = nlohmann::json::parse(file);
    std::string name = j["name"];
    std::map <std::string, int> stats = j["stats"];
    std::string description = j["description"];
    return NPC_tuple {name, stats, description};
}

Parser::class_tuple Parser::parseClass() {
    if (!file.is_open())
        openFileIn();
    nlohmann::json j = nlohmann::json::parse(file);
    std::string name = j["name"];
    std::map <std::string, int> stats = j["stats"];
    std::string description = j["description"];
    return class_tuple {name, stats, description};
}

// TODO: Implement parsing Actions
/*void Parser::parseAbility() {
    if (!file.is_open())
        openFileIn();
    nlohmann::json j = nlohmann::json::parse(file);
    std::string name = j["name"];
    std::string description = j["description"];
}*/

Parser::weapon_tuple Parser::parseWeapon() {
    if (!file.is_open())
        openFileIn();
    nlohmann::json j = nlohmann::json::parse(file);
    std::string name = j["name"];
    std::map <std::string, int> stats = j["stats"];
    std::string description = j["description"];
    return weapon_tuple {name, stats, description};
}

