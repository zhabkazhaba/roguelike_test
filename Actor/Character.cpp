#include "Character.h"

#include <utility>
#include <stdexcept>
#include <iostream>

Character::Character() : Actor() {
    CharacterSpecification.char_class = nullptr;
    CharacterSpecification.char_skills = {};

    BaseStats.strength = 0;
    BaseStats.intelligence = 0;
    BaseStats.agility = 0;
    BaseStats.endurance = 0;
    BaseStats.luck = 0;
    BaseStats.corruption = 0;
}

Character* Character::CreateInstancePtr(std::string name, Class *ch_class, std::vector<Skill> ch_skills,
                                                  int exp, int level, std::vector<std::pair<Item, unsigned int>> ch_items) {
    if (instance == nullptr) {
        instance = new Character();
        instance->ActorStats.name = std::move(name);
        instance->CharacterSpecification.char_class = ch_class;
        instance->CharacterSpecification.char_skills = std::move(ch_skills);
        instance->ActorStats.exp = exp;
        instance->ActorStats.level = level;
        instance->inventory = std::move(ch_items);
        instance->ActorStats.exp_required = DEFAULT_EXP_REQ * (level + 1);
        return instance;
    } else {
        throw std::runtime_error("Character instance already exists");
    }
}

Character::~Character() {
    CharacterSpecification.char_class = nullptr;
    CharacterSpecification.char_skills = {};
    inventory = {};
}

void Character::setName(std::string name) {
    name.length() < 32 ? name = std::move(name) : throw std::out_of_range("Name is too long");
}

void Character::setClass(Class *ch_class) {
    CharacterSpecification.char_class = ch_class;
}

void Character::setLevel(unsigned int level) {
    level < MAX_LEVEL ? ActorStats.level = level : throw std::out_of_range("Level should be less than 60");
}

void Character::setExp(unsigned int exp) {
    ActorStats.exp = exp;
}


// TODO: Actors state should be handled by Game or Map class, which checks on state of each actor object.
// Actor object tells it's state by either throwing false ("I'm dead") or true ("I'm alive")
bool Character::stateCheck() {
    if (ActorStats.hp <= 0) {
        // Placeholder for death
        return false;
    }
    if (ActorStats.exp_required <= ActorStats.exp) {
        levelUp();
    }
    return true;
}

void Character::levelUp() {
    // TODO: Change placeholder for stat
    std::string stat = "strength";
    if (ActorStats.level < MAX_LEVEL) {
        ActorStats.level += 1;
        ActorStats.exp_required = DEFAULT_EXP_REQ * (ActorStats.level + 1);
        ActorStats.level % 5 == 0 ? distributePoints(2, stat) : distributePoints(1, stat);
    }
}

void Character::distributePoints(unsigned int points, const std::string &stat) {
    if (points > 0) {
        if (stat == "strength") {
            BaseStats.strength += points;
            ActorStats.hp += points * 10;
        } else if (stat == "intelligence") {
            BaseStats.intelligence += points;
            ActorStats.mp += points * 10;
        } else if (stat == "agility") {
            BaseStats.agility += points;
            ActorStats.hp += points * 5;
        } else if (stat == "endurance") {
            BaseStats.endurance += points;
            ActorStats.hp += points * 15;
        } else if (stat == "luck") {
            BaseStats.luck += points;
            ActorStats.hp += points * 3;
            ActorStats.mp += points * 3;
        } else if (stat == "corruption") {
            BaseStats.corruption += points;
            ActorStats.hp -= points * 5;
        } else {
            throw std::invalid_argument("Invalid stat");
        }
    } else {
        throw std::invalid_argument("Invalid points");
    }
}