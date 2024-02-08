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

void Actor::changePosition(short x, short y) {
    if (x >= XY_BORDERS.first && x <= XY_BORDERS.second && y >= XY_BORDERS.first && y <= XY_BORDERS.second) {
        position = std::make_pair(x, y);
    } else {
        std::cerr << "Error: Wrong position coordinates.";
    }
}