#include "Level.h"

Level::Level() {

    enemies.push_back(Enemy());
}

int Level::enemy_count() const {
    return static_cast<int>(enemies.size());
}

int Level::weapon_count() const {
    return static_cast<int>(weapons.size());
}