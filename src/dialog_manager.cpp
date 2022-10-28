#include "dialog_manager.hpp"
#include "game_manager.hpp"

#include <stdexcept>

namespace foxiii {
    DialogManager::DialogManager() {
        if(TTF_Init() != 0) {
            throw std::runtime_error("Failed to init SDL2 ttf");
        }

        font = TTF_OpenFont("../resources/Inter-VariableFont_slnt,wght.ttf", 24);
        if(!font) {
            throw std::runtime_error("Failed to open font");
        }

        currentMessage = "My name is Foxiii. Kill all heterosexuals. Make the world more colorful :3";
    }

    DialogManager::~DialogManager() noexcept {
        TTF_CloseFont(font);

        TTF_Quit();
    }

    void DialogManager::update(SDL_Renderer* renderer, GameManager* gameManager) noexcept {
        if(gameManager->getScore() != 0) {
            currentMessage = "Score: " + std::to_string(gameManager->getScore());
        }

        SDL_Surface* surface = TTF_RenderText_Solid(font, currentMessage.c_str(), {255, 255, 255});
        SDL_Texture* messageTexture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_Rect rect;
        rect.x = 0;
        rect.y = 0;
        SDL_QueryTexture(messageTexture, nullptr, nullptr, &rect.w, &rect.h);

        SDL_RenderCopy(renderer, messageTexture, nullptr, &rect);

        SDL_DestroyTexture(messageTexture);
        SDL_FreeSurface(surface);
    }
}