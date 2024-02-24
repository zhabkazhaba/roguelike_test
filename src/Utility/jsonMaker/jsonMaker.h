#ifndef ROGUELIKE_TEST_JSONMAKER_H
#define ROGUELIKE_TEST_JSONMAKER_H


#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

class jsonMaker {
private:
    enum Modes {
        NPC,
        CLASS,
        ABILITY,
        WEAPON
    };
    std::string filename;
    Modes mode;
    std::fstream file;
public:
    jsonMaker();
    jsonMaker(const std::string& init_file, Modes init_mode);
    jsonMaker(jsonMaker &o);
    ~jsonMaker();
    void openFileOut(const std::string& input = "");
    void openFileIn(const std::string& input = "");
    void closeFile();
    void readFile(const std::string& input = "");
    void setMode(Modes mode);
    void setFilename(const std::string& input);
    void write();
};


#endif //ROGUELIKE_TEST_JSONMAKER_H
