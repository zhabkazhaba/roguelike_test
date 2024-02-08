//
// Created by zhabkazhaba on 2/8/24.
//

#ifndef ROGUELIKE_TEST_ATTRIBUTE_H
#define ROGUELIKE_TEST_ATTRIBUTE_H


#include <string>

/**
 * Base class for any attributes (buffs or debuffs) that can be assigned to an actor or NPC
 */
class Attribute {
private:
    std::string name;
    unsigned int duration;
    bool is_character_specific;
};


#endif //ROGUELIKE_TEST_ATTRIBUTE_H
