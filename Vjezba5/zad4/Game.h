#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <string>
#include "Level.h"
#include "Player.h"

class Game {
    std::string title;
    Level level;
    Player player;

public:
    Game(const std::string& title, const std::string& player_name);
    void print() const;
};