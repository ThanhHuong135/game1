#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include "sprite.h"
#include "obstacle.h"

Obstacle::Obstacle(int x, int y, SDL_Texture* tex, int speed)
    : x(x), y(y), texture(tex), speed(speed), passed(false) {}

void Obstacle::update(int& score) {
    x -= speed; // Di chuyển sang trái

    if (x < -50) {  // Nếu chướng ngại vật biến mất khỏi màn hình
        x = 800;    // Reset lại vị trí bên phải màn hình
        passed = false;
        score++;    // Tăng điểm ở đây luôn
    }
}

void Obstacle::render(Graphics &graphics) {
    graphics.renderTexture(texture, x, y);
}
SDL_Rect Obstacle::getRect() {
    return {x + 13, y + 25, width, height};
}
