//
// Created by zhabkazhaba on 2/3/24.
//

#include "Character.h"

#include <utility>
#include <stdexcept>

Character::Character() {
    InitStats.name = "";
    InitStats.char_class = nullptr;
    InitStats.char_skills = {};

    MutStats.level = 0;
    MutStats.exp = 0;
    MutStats.char_items = {};
}

Character::Character(std::string name, Class *ch_class, std::vector<Skill> ch_skills, int exp, int level,
                     std::vector<Item> ch_items) {
    InitStats.name = std::move(name);
    InitStats.char_class = ch_class;
    InitStats.char_skills = std::move(ch_skills);

    MutStats.level = level;
    MutStats.exp = exp;
    MutStats.char_items = std::move(ch_items);
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

void Character::setLevel(int level) {
    level < MAX_LEVEL ? MutStats.level = level : throw std::out_of_range("Level should be less than 60");
}

void Character::setExp(int exp) {
    MutStats.exp = exp;
}

