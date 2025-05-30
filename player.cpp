#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include "sprite.h"
#include "player.h"

Player::Player(int startX, int startY) {
    x = startX;
    y = startY;
    width = 62;
    height = 130;
    velocityY = 0;
    isJumping = false;
}

void Player::jump() {
    if (!isJumping) {
        velocityY = JUMP_FORCE;
        isJumping = true;
    }
}

void Player::update() {
    y += velocityY;
    velocityY += GRAVITY;

    // Khi chạm đất, đặt lại vị trí chuẩn
    if (y >= 351) {
        y = 351;
        velocityY = 0;
        isJumping = false;
    }

    sprite.tick();  // Chuyển đổi frame ảnh
}

void Player::render(SDL_Renderer* renderer) {
    SDL_Rect dest = { x, y, width, height };
    SDL_RenderCopy(renderer, sprite.texture, sprite.getCurrentClip(), &dest);
}

SDL_Rect Player::getRect() {
    return {x + 80, y, sprite.width, sprite.height};
}
