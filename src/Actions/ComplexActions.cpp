#include <iostream>
#include "ComplexActions.h"

CharacterAttack::CharacterAttack(Map *curr, Character *attacker, std::pair<unsigned short, unsigned short> target) {
    this->current_level = curr;
    this->attacker = attacker;
    this->target = target;
}

void CharacterAttack::execute() {
    if (current_level->getCellAt(target)->getActor() != nullptr) {
        dealDamageOnce(attacker, current_level->getCellAt(target)->getActor(),
                       attacker->calculateDamage());
    } else {
        std::cerr << "Error: No actor to attack.";
    }
}