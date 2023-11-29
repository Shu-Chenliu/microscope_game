#include "StartScreen.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "game.h"
#include<iostream>
using namespace std;
StartScreen::StartScreen(SDL_Renderer* _renderer, string st1, string st2, const char* color) : Screen(_renderer)
{
    cout << "StartScreen constructor()!" << endl;

    arrow = new GameObject("assets/arrow.png", 5, 280, 517, 483, 0.1, 0.1);
    screen = new GameObject("assets/start.png", 0, 0, 800, 640);
    const char* edit = st1.c_str();
    const char* start = st2.c_str();
    objTexture1 = TextureManager::loadFont(edit, color);
    objTexture2 = TextureManager::loadFont(start, color);
    title = TextureManager::loadFont("microbial war", color);
    srcR1.x = 0;
    srcR1.y = 0;
    srcR1.w = 150;
    srcR1.h = 30;
    destR1.x = 150;
    destR1.y = 250;
    destR1.w = 300;
    destR1.h = 100;
    srcR2.x = 0;
    srcR2.y = 0;
    srcR2.w = 100;
    srcR2.h = 30;
    destR2.x = 150;
    destR2.y = 430;
    destR2.w = 150;
    destR2.h = 100;
    srcRt.x = 0;
    srcRt.y = 0;
    srcRt.w = 400;
    srcRt.h = 30;
    destRt.x = 50;
    destRt.y = 30;
    destRt.w = 400;
    destRt.h = 100;
}

StartScreen::~StartScreen()
{
    cout << "StartScreen deconstructor()!" << endl;
}

void StartScreen::handleEvents(const Uint8* keystate, bool& start, bool& edit) {
    SDL_Event event;
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_KEYDOWN:
        if (keystate[SDL_SCANCODE_DOWN] && arrow->getypos() == 280) {
            arrow->setypos(arrow->getypos() + 180);
        }
        else if (keystate[SDL_SCANCODE_UP] && arrow->getypos() == 460) {
            //cout << "455U pos:" << arrow->getypos() << endl;
            arrow->setypos(arrow->getypos() - 180);
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 280) {
            //cout << "1pos:" << arrow->getypos() << endl;
            start = true;
            edit = true;
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 460) {
            //cout << "3pos:" << arrow->getypos() << endl;
            start = false;
        }
        break;
    case SDL_KEYUP:
        break;
    default:
        break;
    }
}

void StartScreen::update() {
    screen->update();
    arrow->update();
}

void StartScreen::render()
{
    SDL_RenderClear(renderer);
    // this is where we put things to render
    screen->render();
    arrow->render();
    SDL_RenderCopy(Game::renderer, objTexture1, &srcR1, &destR1);
    SDL_RenderCopy(Game::renderer, objTexture2, &srcR2, &destR2);
    SDL_RenderCopy(Game::renderer, title, &srcRt, &destRt);
    SDL_RenderPresent(renderer);
}