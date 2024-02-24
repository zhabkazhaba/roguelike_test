#ifndef ROGUELIKE_TEST_CHANCE_HPP
#define ROGUELIKE_TEST_CHANCE_HPP

#include <utility>

class chance {
public:
    short value;
    short min;
    short max;

    chance(short chance) { //NOLINT
        if (chance < 0) {
            value = 0;
        } else if (chance > 100) {
            value = 100;
        } else {
            value = chance;
        }
        min = value;
        max = value;
    }

    chance(short min, short max) {
        if (min < 0) {
            min = 0;
        } else if (min > 100) {
            min = 100;
        } else {
            min = min;
        }
        if (max < 0) {
            max = 0;
        } else if (max > 100) {
            max = 100;
        } else {
            max = max;
        }
        value = (min + max) / 2;
    }

    chance(short chance, short min, short max) {
        if (chance < 0) {
            value = 0;
        } else if (chance > 100) {
            value = 100;
        } else {
            value = chance;
        }
        if (min < 0) {
            min = 0;
        } else if (min > 100) {
            min = 100;
        } else {
            min = min;
        }
        if (max < 0) {
            max = 0;
        } else if (max > 100) {
            max = 100;
        } else {
            max = max;
        }
    }

    chance() : value(0) {}
    chance(const chance &other) : value(other.value), min(other.min), max(other.max) {} //NOLINT
    chance &operator=(const chance &other) = default;
    ~chance() = default;

    bool operator==(const chance &other) const {
        return value == other.value;
    }
    bool operator!=(const chance &other) const {
        return value != other.value;
    }
    bool operator<(const chance &other) const {
        return value < other.value;
    }
    bool operator>(const chance &other) const {
        return value > other.value;
    }

    void linearRange(signed short range) {
        value - range < 0 ? min = 0 : min = value - range;
        value + range > 100 ? max = 100 : max = value + range;
    }

    template<typename T>
    std::pair<T, T> operator()(T val) {
        return std::make_pair(val * min / 100, val * max / 100);
    }
};

#endif //ROGUELIKE_TEST_CHANCE_HPP
