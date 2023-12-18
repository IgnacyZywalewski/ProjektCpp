#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Render {
public:
    Render(SDL_Renderer* renderer, int screenWidth, int screenHeight);
    ~Render();

    void renderHealth(int health);
    void renderScore(int score);
    void renderFPS();
    void renderPauseButton(SDL_Texture* pauseTexture);

    void renderStartScreen();
    void renderCharacterSelectionScreen( SDL_Texture* warriorTexture, SDL_Texture* wizardTexture);
    void renderEndGameScreen();

private:
    SDL_Renderer* renderer;
    SDL_Color textColor;
    TTF_Font* font;

    int screenWidth;
    int screenHeight;
};
