#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <string>
#include "Level.h"

class Player {
    std::string name;
    const Level& level;

public:
    Player(const std::string& name, const Level& level);
    void print() const;
};