#pragma once
#include "Screen.h"
#include "game.h"
#include <string>
using namespace std;
class StartScreen : public Screen
{
public:
    explicit StartScreen(SDL_Renderer* _renderer, string st1, string st2, const char* color);
    ~StartScreen();
    virtual void handleEvents(const Uint8* keystate, bool& start, bool& edit);
    virtual void update() override;
    virtual void render() override;
private:
    SDL_Texture* objTexture1;
    SDL_Rect srcR1, destR1;
    SDL_Texture* objTexture2;
    SDL_Rect srcR2, destR2;
    SDL_Texture* title;
    SDL_Rect srcRt, destRt;
};