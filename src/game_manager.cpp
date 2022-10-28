#include "game_manager.hpp"

#include <stdexcept>

SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer) {
    SDL_Surface* surface = SDL_LoadBMP(path);
    if(!surface) {
        throw std::runtime_error("Failed to load texture");
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture) {
        throw std::runtime_error("Failed to create texture");
    }

    SDL_FreeSurface(surface);

    return texture;
}

namespace foxiii {
    GameManager::GameManager(SDL_Renderer* renderer1) {
        renderer = renderer1;

        fox = loadTexture("../resources/fox.bmp", renderer);
        enemyTex = loadTexture("../resources/enemy.bmp", renderer);
    }

    GameManager::~GameManager() {
        SDL_DestroyTexture(enemyTex);
        SDL_DestroyTexture(fox);
    }

    void GameManager::update() noexcept {
        player.bounds_check();
        player.movement();

        if(player.shouldKillEnemy(enemy)) {
            enemy.x = rand() % 1100;
            enemy.y = rand() % 650;

            score++;
        }

        SDL_Rect rect;
        rect.x = player.getX();
        rect.y = player.getY();
        rect.w = 100;
        rect.h = 88;

        SDL_RenderCopy(renderer, fox, nullptr, &rect);

        rect.x = enemy.x;
        rect.y = enemy.y;

        SDL_RenderCopy(renderer, enemyTex, nullptr, &rect);
    }
}