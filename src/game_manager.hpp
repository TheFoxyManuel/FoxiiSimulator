#pragma once

#include <SDL/SDL.h>

#define FOXIII_PLAYER_SPEED 3

namespace foxiii {
    enum class Direction {
        Left,
        Right,
        Up,
        Down
    };

    struct Enemy final {
        int x;
        int y;

        Enemy() : x(0), y(0) {}
        Enemy(int x, int y) noexcept : x(x), y(y) {}
    };

    class Player final {
        int x = 0;
        int y = 400;
        Direction direction = Direction::Right;

    public:
        void bounds_check() noexcept {
            if(x < 0) x = 0;
            if(y < 0) y = 0;

            if(x > 1180) {
                x = 1180;
            }

            if(y > 632) {
                y = 632;
            }
        }

        void movement() noexcept {
            const Uint8 *state = SDL_GetKeyboardState(NULL);
            if(state[SDL_SCANCODE_UP]) {
                move(0, -1);
            }
            if(state[SDL_SCANCODE_DOWN]) {
                move(0, 1);
            }
            if(state[SDL_SCANCODE_LEFT]) {
                move(-1, 0);
            }
            if(state[SDL_SCANCODE_RIGHT]) {
                move(1, 0);
            }
        }

        void move(int xd, int yd) noexcept {
            x += xd * FOXIII_PLAYER_SPEED;
            y += yd * FOXIII_PLAYER_SPEED;
        }

        void setDirection(Direction direction1) noexcept {
            direction = direction1;
        }

        bool shouldKillEnemy(const Enemy& enemy) {
            int xd = enemy.x - x;
            int yd = enemy.y - y;

            int d = xd + yd;
            int distance = (int) sqrtf((float)(d * d));

            return distance < 50;
        }

        int getX() noexcept { return x; }
        int getY() noexcept { return y; }
    };

    class GameManager final {
        SDL_Texture* fox;

        SDL_Texture* enemyTex;

        int score = 0;

        Player player;
        Enemy enemy;

        SDL_Renderer* renderer;
    public:
        GameManager(SDL_Renderer* renderer1);
        ~GameManager();

        inline int getScore() noexcept {
            return score;
        }

        void update() noexcept;
    };
}