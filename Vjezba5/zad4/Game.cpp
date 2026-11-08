#include <iostream>
#include "Game.h"

Game::Game(const std::string& title, const std::string& player_name)
    : title(title), level(), player(player_name, level) {}

void Game::print() const {
    std::cout << title << '\n';
    player.print();
}