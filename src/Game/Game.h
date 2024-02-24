#ifndef ROGUELIKE_TEST_GAME_H
#define ROGUELIKE_TEST_GAME_H


#include <vector>
#include "Map.h"
#include "Input.h"
#include "../Actions/Actions.h"
#include "../Actor/Character.h"

class Game {
private:
    unsigned long turn;
    std::vector<Map> levels;
protected:
    Map *current_level;
    std::string current_action;
    Character *player;
public:
    Game();
    Game(Game const &) = delete;
    ~Game();
    int GameLoop();
    void initializeGame();
    void handleInput(Input input);
    void advanceTurn(Input input);
};


#endif //ROGUELIKE_TEST_GAME_H
