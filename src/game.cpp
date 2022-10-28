#include "game.hpp"
#include "dialog_manager.hpp"
#include "game_manager.hpp"
#include <iostream>
#include <stdexcept>

namespace foxiii {
    Game::Game() {
        if(SDL_Init(SDL_INIT_EVERYTHING != 0)) {
            throw std::runtime_error("Failed to initialize SDL2");
        }

        window = SDL_CreateWindow("Foxiii", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
        if(!window) {
            throw std::runtime_error("Failed to create window");
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if(!renderer) {
            throw std::runtime_error("Failed to create renderer");
        }

        dialogManager = new DialogManager;
        gameManager = new GameManager(renderer);
    }

    Game::~Game() noexcept {
        delete gameManager;
        delete dialogManager;

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);

        SDL_Quit();
    }

    void Game::render() noexcept {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
        SDL_RenderClear(renderer);

        dialogManager->update(renderer, gameManager);
        gameManager->update();

        SDL_RenderPresent(renderer);
    }

    void Game::start() {
        std::cout << "Starting Foxiii by TheFoxyManuel :3" << std::endl;

        bool running = true;
        while(running) {
            SDL_Event event;
            while(SDL_PollEvent(&event) != 0) {
                if(event.type == SDL_QUIT) {
                    running = false;
                }
            }

            render();
        }
    }
}