#include "instruction.h"
#include "defs.h"
void Instruction::show(Graphics& graphics, TTF_Font* font) {
    SDL_Color textColor = {255, 255, 255};
    SDL_Texture* instructionText = graphics.renderText("Press SPACE to jump.", font, textColor);
    SDL_Texture* instructionText2 = graphics.renderText("Press any key to start.", font, textColor);

    SDL_Texture* Background = graphics.loadTexture(BACKGROUND);

    bool waiting = true;
    SDL_Event e;

    while (waiting) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                exit(0);
            }
            else if (e.type == SDL_KEYDOWN) {
                waiting = false; // Thoát vòng lặp khi người chơi nhấn phím bất kỳ
            }
        }
        graphics.renderTexture(Background, 0, 0);
        graphics.renderTexture(instructionText, 0, 200); // Hiển thị hướng dẫn
        graphics.renderTexture(instructionText2, 0, 250);
        graphics.presentScene();
    }

    SDL_DestroyTexture(instructionText);
}
