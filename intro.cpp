#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "intro.h"

// Khởi tạo intro (load ảnh, đặt vị trí)
void Intro::init(SDL_Renderer* renderer) {
    // Load background
    SDL_Surface* bgSurface = IMG_Load(BACKGROUND);
    backgroundTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
    SDL_FreeSurface(bgSurface);

    // Load logo
    SDL_Surface* logoSurface = IMG_Load(MAN_SPRITE_FILE);
    logoTexture = SDL_CreateTextureFromSurface(renderer, logoSurface);
    SDL_FreeSurface(logoSurface);

    // Load nút Play
    SDL_Surface* playSurface = IMG_Load(PLAY_BOTTOM);
    playButtonTexture = SDL_CreateTextureFromSurface(renderer, playSurface);
    SDL_FreeSurface(playSurface);

    // Định vị logo và nút Play
    logoRect = {250, 100, 300, 150};      // (X, Y, Width, Height)
    playButtonRect = {325, 300, 150, 150}; // (X, Y, Width, Height)
}

// Hiển thị intro (chờ người chơi nhấn Play)
bool Intro::show(SDL_Renderer* renderer) {
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

                // Nếu click vào logo, thoát game
                if (mouseX >= logoRect.x && mouseX <= logoRect.x + logoRect.w &&
                    mouseY >= logoRect.y && mouseY <= logoRect.y + logoRect.h) {
                    std::cout << "Clicked on logo -> Exiting game..." << std::endl;
                    exit(0);
                }

                // Nếu click vào nút Play, bắt đầu game
                if (mouseX >= playButtonRect.x && mouseX <= playButtonRect.x + playButtonRect.w &&
                    mouseY >= playButtonRect.y && mouseY <= playButtonRect.y + playButtonRect.h) {
                    std::cout << "Clicked Play -> Starting game..." << std::endl;
                    return true; // Thoát khỏi màn hình intro, vào game
                }
            }
        }

        // Vẽ background game
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

        // Vẽ logo và nút Play
       // SDL_RenderCopy(renderer, logoTexture, NULL, &logoRect);
        SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);

        // Cập nhật màn hình
        SDL_RenderPresent(renderer);
    }
    return false;
}

// Giải phóng bộ nhớ
void Intro::clean() {
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(logoTexture);
    SDL_DestroyTexture(playButtonTexture);
}
