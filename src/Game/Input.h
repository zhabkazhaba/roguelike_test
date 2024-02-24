#ifndef ROGUELIKE_TEST_INPUT_H
#define ROGUELIKE_TEST_INPUT_H

enum class InputType {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    ATTACK,
    HEAL
};

class Input {
private:
    InputType type;
public:
    InputType getType() const;
};


#endif //ROGUELIKE_TEST_INPUT_H
