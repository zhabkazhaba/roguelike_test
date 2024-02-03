//
// Created by zhabkazhaba on 2/3/24.
//

#ifndef ROGUELIKE_TEST_CHARACTER_H
#define ROGUELIKE_TEST_CHARACTER_H

const unsigned int MAX_LEVEL = 60;

#include <string>
#include <vector>
#include "Class.h"
#include "Skill.h"
#include "Item/Item.h"

// TODO: I will handle this class by myself. It should unify all characters stats + control various things
// TODO: Such as distribution of skill points, inventory, leveling up, dying, having special effects and so on.

class Character {
private:
    struct {
        std::string name;
        Class *char_class;
        std::vector<Skill> char_skills;
    } InitStats;

    struct {
        unsigned int hp;
        unsigned int xp;
        unsigned int level;
        unsigned int exp;
        std::vector<Item> char_items;
    } MutStats;

    std::pair<int, int> position;

public:
    Character();
    Character(std::string name, Class *ch_class, std::vector<Skill> ch_skills,
              int exp, int level, std::vector<Item> ch_items);
    ~Character();

    void setName(std::string name);
    void setClass(Class *ch_class);
    void setLevel(unsigned int level);
    void setExp(unsigned int exp);
};


#endif //ROGUELIKE_TEST_CHARACTER_H
