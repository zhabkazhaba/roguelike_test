/*
 * Base class for any creatures actively presented at the map (including player).
 */

#ifndef ROGUELIKE_TEST_ACTOR_H
#define ROGUELIKE_TEST_ACTOR_H

#include <string>
#include <vector>
#include <random>
#include "Class.h"
#include "../Actions/Skill.h"
#include "../Item/Item.h"
#include "Attribute.h"

const unsigned short MAX_LEVEL = 60;
const unsigned short DEFAULT_HP = 30;
const unsigned short DEFAULT_MP = 10;
const unsigned short DEFAULT_LEVEL = 1;
const unsigned short DEFAULT_EXP = 0;
const unsigned short DEFAULT_EXP_REQ = 90;

/*
 * Macros to be changed later
 */
const std::pair<unsigned int, unsigned int> XY_BORDERS = std::make_pair(0,100);

class Actor {
protected:
    struct {
        std::string name;
        unsigned int hp;
        unsigned int max_hp;
        unsigned int mp;
        unsigned int max_mp;
        unsigned int level;
        unsigned int exp;
        unsigned int exp_required;
        std::vector<std::pair<Attribute, unsigned int>> attributes;
    } ActorStats{};

    /**
     * Vector of items with paired COUNT value
     */
    std::vector<std::pair<Item, unsigned int>> inventory;

    std::pair<unsigned short, unsigned short> position;
public:
    Actor();
    Actor(Actor &other);
    ~Actor();

    virtual bool stateCheck() = 0;
    virtual unsigned int calculateDamage() const = 0;

    void setHp(unsigned int hp);
    void setMp(unsigned int mp);
    void setPosition(unsigned short x, unsigned short y);
    void setPosition(std::pair<unsigned short, unsigned short> pos);

    unsigned int getHp() const;
    unsigned int getMp() const;
    std::pair<unsigned short, unsigned short> getPosition() const;
};


#endif //ROGUELIKE_TEST_ACTOR_H
