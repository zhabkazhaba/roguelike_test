#include "NPC.h"

NPC::NPC() : Actor() {
    spawn_rate = 0;
}

NPC::NPC(NPC &other) : Actor(other) {
    spawn_rate = other.spawn_rate;
}

NPC::~NPC() = default;

bool NPC::stateCheck() {
    if (ActorStats.hp <= 0) {
        return false;
    }
    return true;
}