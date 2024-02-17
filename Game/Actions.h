#ifndef ROGUELIKE_TEST_ACTIONS_H
#define ROGUELIKE_TEST_ACTIONS_H

#include "../Actor/Actor.h"
#include "Map.h"

class Action {
protected:
    Map *current_level;
public:
    virtual ~Action() = default;
    virtual void execute() = 0;
};

class moveFromTo : public Action {
private:
    std::pair<unsigned short, unsigned short> from;
    std::pair<unsigned short, unsigned short> to;
public:
    moveFromTo(Map *curr, std::pair<unsigned short, unsigned short> from, std::pair<unsigned short, unsigned short> to);
    void execute() override;
};

class moveActorTo : public Action {
private:
    Actor *actor;
    std::pair<unsigned short, unsigned short> to;
public:
    moveActorTo(Map *curr, Actor *actor, std::pair<unsigned short, unsigned short> to);
    void execute() override;
};

class dealDamageOnce : public Action {
private:
    Actor *dealer;
    Actor *target;
    unsigned int damage;
public:
    dealDamageOnce(Actor *dealer, Actor *target, unsigned int damage);
    void execute() override;
};

class healOnce : public Action {
private:
    Actor *healer;
    Actor *target;
    unsigned int heal;
public:
    healOnce(Actor *healer, Actor *target, unsigned int heal);
    void execute() override;
};

#endif //ROGUELIKE_TEST_ACTIONS_H
