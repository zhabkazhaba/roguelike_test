#include "Game.h"
#include "ComplexActions.h"

Game::Game() {
    turn = 0;
    current_level = &levels[0];
    current_action = "none";
    //player = new Character(...)
}

Game::~Game() {
    delete player;
    player = nullptr;
    delete current_level;
    current_level = nullptr;
    levels.clear();
    levels.shrink_to_fit();
}

void Game::handleInput(Input input) {
    switch (input.getType()) {
        case InputType::MOVE_UP:
        {
            std::pair<unsigned short, unsigned short> target_position = std::make_pair(player->getPosition().first,
                                                                                       player->getPosition().second + 1);
            moveActorTo command(current_level, player, target_position);
            command.execute();
        }
            break;
        case InputType::MOVE_DOWN:
        {
            std::pair<unsigned short, unsigned short> target_position = std::make_pair(player->getPosition().first,
                                                                                       player->getPosition().second - 1);
            moveActorTo command(current_level, player, target_position);
            command.execute();
        }
            break;
        case InputType::MOVE_LEFT:
        {
            std::pair<unsigned short, unsigned short> target_position = std::make_pair(player->getPosition().first - 1,
                                                                                       player->getPosition().second);
            moveActorTo command(current_level, player, target_position);
            command.execute();
        }
            break;
        case InputType::MOVE_RIGHT:
        {
            std::pair<unsigned short, unsigned short> target_position = std::make_pair(player->getPosition().first + 1,
                                                                                       player->getPosition().second);
            moveActorTo command(current_level, player, target_position);
            command.execute();
        }
            break;
        case InputType::ATTACK: {
            //TODO: Implement attack input
            int x, y = 0;
            std::pair<unsigned short, unsigned short> target_position = std::make_pair(x, y);
            CharacterAttack command(current_level, player, target_position);
            command.execute();
            break;
        }
        case InputType::HEAL:
            //TODO: Implement simple heal
            break;
    }
}

void Game::advanceTurn(Input input) {
    handleInput(input);

    turn++;
}