#pragma once
#include "Screen.h"
#include "game.h"
using namespace std;
class editScreen :public Screen
{
public:
    explicit editScreen(SDL_Renderer* _renderer, const char* color);
    ~editScreen();
    virtual void handleEvents(const Uint8* keystate, bool& start, bool& edit,int* team);
    virtual void update() override;
    virtual void render() override;
private:
    SDL_Texture* objTexture1;
    SDL_Rect srcR1, destR1;
    SDL_Texture* objTexture2;
    SDL_Rect srcR2, destR2;
    SDL_Texture* objTexture3;
    SDL_Rect srcR3, destR3;
    int pic;
    string left;
    int teamSize;
};

