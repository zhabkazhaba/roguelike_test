#ifndef ROGUELIKE_TEST_MAP_H
#define ROGUELIKE_TEST_MAP_H


#include <map>
#include "Cell.h"

class Map {
    // TODO: Map class is set to handle many things: properties of cells, random generations, dynamic cell state control
private:
    unsigned int level;
    std::map<std::pair<unsigned short, unsigned short>, Cell> cells;
public:
    Cell* getCellAt(std::pair<unsigned short, unsigned short> position);
};


#endif //ROGUELIKE_TEST_MAP_H
