//
// Created by zhabkazhaba on 2/10/24.
//

#include <iostream>
#include "Actions.h"

moveFromTo::moveFromTo(Map *curr, std::pair<unsigned short, unsigned short> from,
                       std::pair<unsigned short, unsigned short> to) {
    current_level = curr;
    this->from = from;
    this->to = to;
}
void moveFromTo::execute() {
    if (current_level->getCellAt(to)->getActor() == nullptr && current_level->getCellAt(from)->getActor() != nullptr) {
        current_level->getCellAt(to)->setActor(current_level->getCellAt(from)->getActor());
        current_level->getCellAt(from)->setActor(nullptr);
    } else {
        std::cerr << "Error: No actor to move or cell is already occupied.";
    }
}

moveActorTo::moveActorTo(Map *curr, Actor *actor, std::pair<unsigned short, unsigned short> to) {
    current_level = curr;
    this->actor = actor;
    this->to = to;
}
void moveActorTo::execute() {
    if (current_level->getCellAt(to)->getActor() == nullptr) {
        current_level->getCellAt(actor->getPosition())->setActor(nullptr); // TODO: check if actor is in the cell (not nullptr
        current_level->getCellAt(to)->setActor(actor);
        actor->setPosition(to.first, to.second);
    } else {
        std::cerr << "Error: Cell is already occupied.";
    }
}

dealDamageOnce::dealDamageOnce(Actor *dealer, Actor *target, unsigned int damage)
                             : dealer(dealer), target(target), damage(damage) {}
void dealDamageOnce::execute() {
    target->setHp(target->getHp() - damage);
}

healOnce::healOnce(Actor *healer, Actor *target, unsigned int heal)
                 : healer(healer), target(target), heal(heal) {}
void healOnce::execute() {
    target->setHp(target->getHp() + heal);
}