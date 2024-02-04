//
// Created by zhabkazhaba on 2/3/24.
//

#ifndef ROGUELIKE_TEST_CHARACTER_H
#define ROGUELIKE_TEST_CHARACTER_H

const unsigned short MAX_LEVEL = 60;
const unsigned short DEFAULT_EXP = 90;

#include <string>
#include <vector>
#include "Class.h"
#include "Skill.h"
#include "Item/Item.h"

// TODO: I will handle this class by myself. It should unify all characters stats + control various things
// TODO: Such as distribution of skill points, inventory, leveling up, dying, having special effects and so on.

class Character {
private:
    static Character *instance;

    struct {
        std::string name;
        Class *char_class;
        std::vector<Skill> char_skills;
    } InitStats;

    struct {
        unsigned int strength;
        unsigned int intelligence;
        unsigned int agility;
        unsigned int endurance;
        unsigned int luck;
        unsigned int corruption;
    } BaseStats;

    struct {
        unsigned int hp;
        unsigned int mp;
        unsigned int level;
        unsigned int exp;
        unsigned int exp_required;
        std::vector<Item> char_items;
    } MutStats;

    // Placeholder for inventory
    std::vector<std::pair<Item, unsigned int>> inventory;

    // Placeholder for position
    std::pair<int, int> position;

    Character();
public:
    static Character *CreateInstancePtr(std::string name, Class *ch_class, std::vector<Skill> ch_skills,
                        int exp, int level, std::vector<Item> ch_items);

    ~Character();

    Character(Character const &) = delete;
    void operator=(Character const &) = delete;

    void setName(std::string name);
    void setClass(Class *ch_class);
    void setLevel(unsigned int level);
    void setExp(unsigned int exp);

    void stateCheck();

    void levelUp();

    void distributePoints(unsigned int points, std::string stat);
};

#endif //ROGUELIKE_TEST_CHARACTER_H
