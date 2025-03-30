#include "endScreen.h"
#include "graphics.h"
#include "defs.h"
EndScreen::EndScreen() {}

void EndScreen::show(Graphics& graphics, ScrollingBackground& background, TTF_Font* font) {
    SDL_Color textColor = {255, 0, 0};  // Màu đỏ
    SDL_Texture* gameOverTexture = graphics.renderText("GAME OVER", font, textColor);

    // Load hình nền khác cho màn hình Game Over
    SDL_Texture* endBackground = graphics.loadTexture(END_BACKGROUND);

    bool waiting = true;
    SDL_Event e;

    while (waiting) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                waiting = false;
            }
        }
        // Vẽ background Game Over mới
        graphics.renderTexture(endBackground, 0, 0);
        // Hiển thị chữ "Game Over" giữa màn hình
        graphics.renderTexture(gameOverTexture, 250, 200);
        graphics.presentScene();
    }

    SDL_DestroyTexture(gameOverTexture); // Giải phóng bộ nhớ
}
