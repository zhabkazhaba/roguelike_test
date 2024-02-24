#include <iostream>
#include "jsonMaker.h"

jsonMaker::jsonMaker() {
    // These values are set by default, no real meaning
    filename = "dump";
    mode = Modes::NPC;
}

jsonMaker::jsonMaker(const std::string &init_file, jsonMaker::Modes init_mode) {
    filename = init_file;
    mode = init_mode;
}

jsonMaker::jsonMaker(jsonMaker &o) {
    filename = o.filename;
    mode = o.mode;
}

jsonMaker::~jsonMaker() {
    file.is_open()  ? file.close() : file.clear();
}


void jsonMaker::openFileOut(const std::string& input) {
    if (file.is_open())
        file.close();
    if (input.empty()) {
        std::string temp = filename + ".json";
        file.open(temp, std::ios::out | std::ios::app);
    }
    else {
        std::string temp = input + ".json";
        file.open(temp, std::ios::out | std::ios::app);
    }
}

void jsonMaker::openFileIn(const std::string& input) {
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

void jsonMaker::closeFile() {
    if (file.is_open())
        file.close();
}

void jsonMaker::setMode(Modes input) {
    mode = input;
}

void jsonMaker::setFilename(const std::string &input) {
    filename = input;
}

void jsonMaker::write() {
    if (!file.is_open()) {
        std::cerr << "jsonMaker: File is not open!";
        return;
    }
    switch (mode) {
        case Modes::NPC: {
            std::cout << "Enter NPC name: ";
            std::string name;
            std::getline(std::cin, name);
            file << "{\n"
                    "\t\"name\": \"" << name <<
                    "\",\n"
                    "\t\"stats\":\n"
                    "\t{\n"
                    "\t\t\"spawn_rate\": 0,\n"
                    "\t\t\"hp\": 0,\n"
                    "\t\t\"mp\": 0,\n"
                    "\t\t\"level\": 0,\n"
                    "\t\t\"attack_strength\": 0,\n"
                    "\t\t\"exp_reward\": 0\n"
                    "\t},\n"
                    "\t\"description\": \"\"\n"
                    "}\n";
            break;
        }
        case Modes::CLASS: {
            std::cout << "Enter class name: ";
            std::string name;
            std::cin >> name;
            file << "{\n"
                    "\t\"name\": \"" << name << "\",\n"
                    "\t\"stats\": [\n"
                    "\t{\n"
                    "\t\t\"strength\": 0,\n"
                    "\t\t\"intelligence\": 0,\n"
                    "\t\t\"agility\": 0,\n"
                    "\t\t\"endurance\": 0,\n"
                    "\t\t\"luck\": 0,\n"
                    "\t\t\"corruption\": 0\n"
                    "\t}\n"
                    "\"description\": \"\"\n"
                    "}\n";
            break;
        }
        case Modes::ABILITY: { // Structure in development
            file << "{\n"
                    "\t\"name\": \"\",\n"
                    "\t\"commands\": [],\n"
                    "\t\"description\": \"\",\n"
                    "}\n";
            break;
        }
        case Modes::WEAPON: {
            file << "{\n"
                    "\t\"name\": \"\",\n"
                    "\t\"damage\": 0,\n"
                    "\t\"attack_speed\": 0,\n"
                    "\t\"weight\": 0,\n"
                    "\t\"description\": \"\"\n"
                    "}";
            break;
        }

        case CHAR_SAVE:
            file << "{\n"
                    "\t\"name\": \"\",\n"
                    "\t\"gender\": \"\",\n"
                    "\t\"class\": \"\",\n"
                    "\t\"skills\": [],\n"
                    "\t\"stats\":\n"
                    "\t{\n"
                    "\t\t\"strength\": 0,\n"
                    "\t\t\"intelligence\": 0,\n"
                    "\t\t\"agility\": 0,\n"
                    "\t\t\"endurance\": 0,\n"
                    "\t\t\"luck\": 0,\n"
                    "\t\t\"corruption\": 0\n"
                    "\t},\n"
                    "\t\"description\": \"\"\n"
                    "}\n";
            break;
    }
}