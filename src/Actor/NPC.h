/*
 * Class for any game-controlled creature, including enemies, neutral creatures, vendors (maybe?)
 */

#ifndef ROGUELIKE_TEST_NPC_H
#define ROGUELIKE_TEST_NPC_H


#include "Actor.h"

class NPC : public Actor {
private:
    unsigned int spawn_rate;
    unsigned int attack_strength;
    unsigned int exp_reward;
public:
    NPC();
    NPC(NPC &other);
    ~NPC();
    bool stateCheck() override;
};


#endif //ROGUELIKE_TEST_NPC_H
