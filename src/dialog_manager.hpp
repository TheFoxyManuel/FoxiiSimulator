#pragma once

#include <string>
#include <string_view>
#include <queue>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

namespace foxiii {
    class GameManager;
    class DialogManager final {
        TTF_Font* font;

        std::string currentMessage;
    public:
        DialogManager();
        ~DialogManager() noexcept;

        void update(SDL_Renderer* renderer, GameManager* gameManager) noexcept;
    };
}