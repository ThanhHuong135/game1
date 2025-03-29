
#ifndef _JUMP__H
#define _JUMP__H

#include <vector>

struct Player {
    int x, y;
    int width, height;
    int velocityY;
    bool isJumping;
    Sprite sprite;

    Player(int startX, int startY);

    void jump();

    void update();

    void render(SDL_Renderer* renderer);
};

#endif
