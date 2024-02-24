#ifndef ROGUELIKE_TEST_COMPLEXACTIONS_H
#define ROGUELIKE_TEST_COMPLEXACTIONS_H

#include "Actions.h"
#include "../Actor/Character.h"

class CharacterAttack : public Action {
private:
    Character *attacker;
    std::pair<unsigned short, unsigned short> target;
public:
    CharacterAttack(Map *curr, Character *attacker, std::pair<unsigned short, unsigned short> target);
    void execute() override;
};


#endif //ROGUELIKE_TEST_COMPLEXACTIONS_H
