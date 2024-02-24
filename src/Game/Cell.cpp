#include "Cell.h"

Cell::Cell() {
    base_texture = "default";
    base_decoration = "default";
    actor = nullptr;
}

Cell::Cell(const std::string& tex, const std::string& dec, Actor* actor) {
    base_texture = tex;
    base_decoration = dec;
    this->actor = actor;
}

Cell::~Cell() = default;

void Cell::setTexture(const std::string& tex) {
    base_texture = tex;
}

void Cell::setDecoration(const std::string& dec) {
    base_decoration = dec;
}

void Cell::setActor(Actor* pActor) {
    this->actor = pActor;
}

const std::string& Cell::getTexture() const {
    return base_texture;
}

const std::string& Cell::getDecoration() const {
    return base_decoration;
}

Actor* Cell::getActor() const {
    return actor;
}
