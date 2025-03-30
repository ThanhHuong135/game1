#include "intro.h"
#include "defs.h"
#include <iostream>
// Khởi tạo intro (load ảnh, chữ, đặt vị trí)
void Intro::init(Graphics& graphics) {
    // Load background và nút Play
    backgroundTexture = graphics.loadTexture(BACKGROUND);
    playButtonTexture = graphics.loadTexture(PLAY_BUTTON);
    // Định vị nút Play
    playButtonRect = {325, 250, 150, 150}; // (X, Y, Width, Height)
    // Load font chữ
    font = graphics.loadFont("Purisa-BoldOblique.ttf", 50);
    if (font) {
        SDL_Color color = {255, 255, 255};  // Màu trắng
        textTexture = graphics.renderText("RUNNING MAN", font, color);
        textRect = {200, 100, 300, 50}; // Vị trí chữ
    }
}
// Hiển thị intro (chờ người chơi nhấn Play)
bool Intro::show(Graphics& graphics) {
    SDL_Event e;
    bool running = true;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                exit(0); // Thoát game khi nhấn nút đóng cửa sổ
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                // Nếu click vào nút Play, vào game
                if (mouseX >= playButtonRect.x && mouseX <= playButtonRect.x + playButtonRect.w &&
                    mouseY >= playButtonRect.y && mouseY <= playButtonRect.y + playButtonRect.h) {
                    std::cout << "Clicked Play -> Starting game..." << std::endl;
                    return true; // Thoát khỏi màn hình intro, vào game
                }
            }
        }
        // Vẽ background
        graphics.renderTexture(backgroundTexture, 0, 0);
        // Vẽ chữ "RUNNING MAN"
        if (textTexture) {
            graphics.renderTexture(textTexture, textRect.x, textRect.y);
        }
        // Vẽ nút Play
        graphics.renderTexture(playButtonTexture, playButtonRect.x, playButtonRect.y);
        // Cập nhật màn hình
        graphics.presentScene();
    }
    return false;
}

// Giải phóng bộ nhớ
void Intro::clean() {
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(playButtonTexture);
    SDL_DestroyTexture(textTexture);
    if (font) {
        TTF_CloseFont(font);
    }
}
