/*
 * Special class for player character.
 */

#ifndef ROGUELIKE_TEST_CHARACTER_H
#define ROGUELIKE_TEST_CHARACTER_H

// TODO: I will handle this class by myself. It should unify all characters stats + control various things
// TODO: Such as distribution of skill points, inventory, leveling up, dying, having special effects and so on.

#include "Actor.h"

class Character : public Actor {
private:
    static Character *instance;

    struct {
        Class *char_class;
        std::vector<Skill> char_skills;
    } CharacterSpecification;

    struct {
        unsigned int strength;
        unsigned int intelligence;
        unsigned int agility;
        unsigned int endurance;
        unsigned int luck;
        unsigned int corruption;
    } BaseStats;

    Character();
public:

    static Character *CreateInstancePtr(std::string name, Class *ch_class, std::vector<Skill> ch_skills,
                        int exp, int level, std::vector<std::pair<Item, unsigned int>> ch_items);

    ~Character();

    Character(Character const &) = delete;
    void operator=(Character const &) = delete;

    void setName(std::string name);
    void setClass(Class *ch_class);
    void setLevel(unsigned int level);
    void setExp(unsigned int exp);

    //TODO: Place stateCheck to Map or Game class
    bool stateCheck() override;
    unsigned int calculateDamage() const override;

    void levelUp();

    void distributePoints(unsigned int points, const std::string& stat);
};

#endif //ROGUELIKE_TEST_CHARACTER_H
