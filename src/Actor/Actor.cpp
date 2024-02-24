#include <iostream>
#include "Actor.h"

Actor::Actor() {
    ActorStats.hp = DEFAULT_HP;
    ActorStats.mp = DEFAULT_MP;
    ActorStats.level = DEFAULT_LEVEL;
    ActorStats.exp = DEFAULT_EXP;
    ActorStats.exp_required = DEFAULT_EXP_REQ;
    inventory = {};
}

Actor::Actor(Actor &other) {
    ActorStats = other.ActorStats;
    inventory = other.inventory;
    position = other.position;
}

Actor::~Actor() = default;

void Actor::setHp(unsigned int hp) {
    ActorStats.hp = hp;
}

void Actor::setMp(unsigned int mp) {
    ActorStats.mp = mp;
}

void Actor::setPosition(unsigned short x, unsigned short y) {
    if (x >= XY_BORDERS.first && x <= XY_BORDERS.second && y >= XY_BORDERS.first && y <= XY_BORDERS.second) {
        position = std::make_pair(x, y);
    } else {
        std::cerr << "Error: Wrong position coordinates.";
    }
}

void Actor::setPosition(std::pair<unsigned short, unsigned short> pos) {
    if (pos.first >= XY_BORDERS.first && pos.first <= XY_BORDERS.second && pos.second >= XY_BORDERS.first && pos.second <= XY_BORDERS.second) {
        position = pos;
    } else {
        std::cerr << "Error: Wrong position coordinates.";
    }

}

unsigned int Actor::getHp() const {
    return ActorStats.hp;
}

unsigned int Actor::getMp() const {
    return ActorStats.mp;
}

std::pair<unsigned short, unsigned short> Actor::getPosition() const {
    return position;
}