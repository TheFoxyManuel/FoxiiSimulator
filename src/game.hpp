#pragma once

#include <SDL/SDL.h>

namespace foxiii {
    class DialogManager;
    class GameManager;
    class Game final {
        SDL_Window* window;
        SDL_Renderer* renderer;

        DialogManager* dialogManager;
        GameManager* gameManager;
    private:
        void render() noexcept;
    public:
        Game();
        ~Game() noexcept;

        void start();
    };
}