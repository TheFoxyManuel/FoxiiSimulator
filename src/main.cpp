#include "game.hpp"

int main(int argc, char** args) {
    foxiii::Game* game = new foxiii::Game;
    game->start();
    delete game;

    return 0;
}
