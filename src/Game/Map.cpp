#include <iostream>
#include "Map.h"

/* void Map::moveFromTo(std::pair<unsigned short, unsigned short> from, std::pair<unsigned short, unsigned short> to) {
    if (cells[to].getActor() == nullptr && cells[from].getActor() != nullptr) {
        cells[to].setActor(cells[from].getActor());
        cells[from].setActor(nullptr);
    } else {
        std::cerr << "Error: No actor to move or cell is already occupied.";
    }
}

void Map::moveActorTo(Actor *actor, std::pair<unsigned short, unsigned short> to) {
    if (cells[to].getActor() == nullptr) {
        cells[to].setActor(actor);
        actor->setPosition(to.first, to.second);
    } else {
        std::cerr << "Error: Cell is already occupied.";
    }
} */

Cell* Map::getCellAt(std::pair<unsigned short, unsigned short> position) {
    return &cells[position];
}