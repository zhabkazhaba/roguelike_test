#ifndef ROGUELIKE_TEST_PARSER_H
#define ROGUELIKE_TEST_PARSER_H

#include <fstream>
#include <map>
#include "../Actions/Actions.h"
enum readMode {
    NPC,
    CLASS,
    ABILITY,
    WEAPON,
    CHAR_SAVE
}

class Parser {
private:
    std::string filename;
    std::fstream file;
    readMode mode;
public:
    using NPC_tuple = std::tuple<std::string, std::map<std::string, int>, std::string>;
    using class_tuple = std::tuple<std::string, std::map<std::string, int>, std::string>;
    using ability_tuple = std::tuple<std::string, std::vector<Action>, std::string>;
    using weapon_tuple = std::tuple<std::string, std::map<std::string, int>, std::string>;
    using char_tuple = std::tuple<std::string, std::string, std::string, std::vector<int>, std::map<std::string, int>, std::string>;

    Parser();
    Parser(readMode init_mode, const std::string& init_file);
    Parser(Parser &o);
    ~Parser();
    void openFileIn(const std::string& input = "");
    void closeFile();
    void setFilename(const std::string& input);

    void parse();
    NPC_tuple parseNPC();
    class_tuple parseClass();
    //ability_tuple parseAbility();
    weapon_tuple parseWeapon();
    char_tuple parseChar();
};


#endif //ROGUELIKE_TEST_PARSER_H
