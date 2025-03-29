#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include "sprite.h"
#include "obstacle.h"

Obstacle::Obstacle(int x, int y, SDL_Texture* tex, int speed)
    : x(x), y(y), texture(tex), speed(speed) {}

void Obstacle::update() {
    x -= speed; // Di chuyển chướng ngại vật sang trái

    // Reset khi ra khỏi màn hình
    if (x < -50) {
        x = 800; // Reset lại phía bên phải
    }
}

void Obstacle::render(Graphics &graphics) {
    graphics.renderTexture(texture, x, y);
}
SDL_Rect Obstacle::getRect() {
    return {x + 13, y + 25, width, height};
}
