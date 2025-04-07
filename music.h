#ifndef MUSIC_H
#define MUSIC_H
#include <SDL_mixer.h>
class MusicPlayer {
public:
    MusicPlayer();
    ~MusicPlayer();

    bool loadMusic();  // Khởi tạo và load sẵn nhạc
    void playBackgroundMusic(int loops = -1);
    void stopBackgroundMusic();

    void playJumpSound();
    void playDieSound();

    void cleanUp();

private:
    Mix_Music* backgroundMusic;
    Mix_Chunk* jumpSound;
    Mix_Chunk* dieSound;
};

#endif
