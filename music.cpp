#include "music.h"
#include <iostream>

MusicPlayer::MusicPlayer() {
    backgroundMusic = nullptr;
    jumpSound = nullptr;
    dieSound = nullptr;
}

MusicPlayer::~MusicPlayer() {
    cleanUp();
}

bool MusicPlayer::loadMusic() {

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "SDL_mixer lỗi: " << Mix_GetError() << std::endl;
        return false;
    }
    // Load sẵn luôn ở đây
    backgroundMusic = Mix_LoadMUS("RunningAway.mp3");
    if (!backgroundMusic) {
        std::cout << "Không tải được nhạc nền: " << Mix_GetError() << std::endl;
        return false;
    }

    jumpSound = Mix_LoadWAV("jump.wav");
    if (!jumpSound) {
        std::cout << "Không tải được âm nhảy: " << Mix_GetError() << std::endl;
        return false;
    }

    dieSound = Mix_LoadWAV("lost.wav");
    if (!dieSound) {
        std::cout << "Không tải được âm chết: " << Mix_GetError() << std::endl;
        return false;
    }

    return true;
}

void MusicPlayer::playBackgroundMusic(int loops) {
    if (Mix_PlayMusic(backgroundMusic, loops) == -1) {
        std::cout << "Lỗi phát nhạc nền: " << Mix_GetError() << std::endl;
    }
}

void MusicPlayer::stopBackgroundMusic() {
    Mix_HaltMusic();
}

void MusicPlayer::playJumpSound() {
    Mix_PlayChannel(-1, jumpSound, 0);
}

void MusicPlayer::playDieSound() {
    Mix_PlayChannel(-1, dieSound, 0);
}

void MusicPlayer::cleanUp() {
    if (backgroundMusic) {
        Mix_FreeMusic(backgroundMusic);
        backgroundMusic = nullptr;
    }
    if (jumpSound) {
        Mix_FreeChunk(jumpSound);
        jumpSound = nullptr;
    }
    if (dieSound) {
        Mix_FreeChunk(dieSound);
        dieSound = nullptr;
    }
    Mix_CloseAudio();
}
