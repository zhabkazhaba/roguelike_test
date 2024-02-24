#ifndef ROGUELIKE_TEST_CELL_H
#define ROGUELIKE_TEST_CELL_H

#include <string>
#include "../Actor/Actor.h"

class Cell {
private:
    std::string base_texture;
    std::string base_decoration;
    Actor *actor;
public:
    Cell();
    Cell(const std::string &tex, const std::string &dec, Actor *actor);
    Cell(Cell const &) = delete;
    ~Cell();

    void setTexture(const std::string &tex);
    void setDecoration(const std::string &dec);
    void setActor(Actor *pActor);

    const std::string& getTexture() const;
    const std::string& getDecoration() const;
    Actor *getActor() const;
};


#endif //ROGUELIKE_TEST_CELL_H
