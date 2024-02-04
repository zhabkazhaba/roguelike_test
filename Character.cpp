//
// Created by zhabkazhaba on 2/3/24.
//

#include "Character.h"

#include <utility>
#include <stdexcept>
#include <iostream>

Character::Character() {
    InitStats.name = "";
    InitStats.char_class = nullptr;
    InitStats.char_skills = {};

    BaseStats.strength = 0;
    BaseStats.intelligence = 0;
    BaseStats.agility = 0;
    BaseStats.endurance = 0;
    BaseStats.luck = 0;
    BaseStats.corruption = 0;

    MutStats.level = 0;
    MutStats.exp = 0;
    MutStats.char_items = {};
}

Character* Character::CreateInstancePtr(std::string name, Class *ch_class, std::vector<Skill> ch_skills,
                                                  int exp, int level, std::vector<Item> ch_items) {
    if (instance == nullptr) {
        instance = new Character();
        instance->InitStats.name = std::move(name);
        instance->InitStats.char_class = ch_class;
        instance->InitStats.char_skills = std::move(ch_skills);
        instance->MutStats.exp = exp;
        instance->MutStats.level = level;
        instance->MutStats.char_items = std::move(ch_items);
        instance->MutStats.exp_required = DEFAULT_EXP * (level + 1);
        return instance;
    } else {
        throw std::runtime_error("Character instance already exists");
    }
}

Character::~Character() {
    InitStats.char_class = nullptr;
    InitStats.char_skills = {};
    MutStats.char_items = {};
}

void Character::setName(std::string name) {
    name.length() < 32 ? InitStats.name = std::move(name) : throw std::out_of_range("Name is too long");
}

void Character::setClass(Class *ch_class) {
    InitStats.char_class = ch_class;
}

void Character::setLevel(unsigned int level) {
    level < MAX_LEVEL ? MutStats.level = level : throw std::out_of_range("Level should be less than 60");
}

void Character::setExp(unsigned int exp) {
    MutStats.exp = exp;
}

void Character::stateCheck() {
    if (MutStats.hp <= 0) {
        // Placeholder for death
        // TODO: Implement death
        std::cout << "You died!";
        exit(0);
    }
    if (MutStats.exp_required <= MutStats.exp) {
        levelUp();
    }
}

void Character::levelUp() {
    // TODO: Change placeholder for stat
    std::string stat = "strength";
    if (MutStats.level < MAX_LEVEL) {
        MutStats.level += 1;
        MutStats.exp_required = DEFAULT_EXP * (MutStats.level + 1);
        MutStats.level % 5 == 0 ? distributePoints(2, stat) : distributePoints(1, stat);
    }
}

void Character::distributePoints(unsigned int points, std::string stat) {
    if (points > 0) {
        if (stat == "strength") {
            BaseStats.strength += points;
            MutStats.hp += points * 10;
        } else if (stat == "intelligence") {
            BaseStats.intelligence += points;
            MutStats.mp += points * 10;
        } else if (stat == "agility") {
            BaseStats.agility += points;
            MutStats.hp += points * 5;
        } else if (stat == "endurance") {
            BaseStats.endurance += points;
            MutStats.hp += points * 15;
        } else if (stat == "luck") {
            BaseStats.luck += points;
            MutStats.hp += points * 3;
            MutStats.mp += points * 3;
        } else if (stat == "corruption") {
            BaseStats.corruption += points;
            MutStats.hp -= points * 5;
        } else {
            throw std::invalid_argument("Invalid stat");
        }
    } else {
        throw std::invalid_argument("Invalid points");
    }
}