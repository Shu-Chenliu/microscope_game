#include "editScreen.h"
#include "TextureManager.h"
#include <string.h>
using namespace std;
editScreen::editScreen(SDL_Renderer* _renderer, const char* color): Screen(_renderer) {
    left = "5";
	objTexture1 = TextureManager::loadFont("5 left", color);
    srcR1.x = 0;
    srcR1.y = 0;
    srcR1.w = 150;
    srcR1.h = 30;
    destR1.x = 400;
    destR1.y = 470;
    destR1.w = 350;
    destR1.h = 100;
    pic = 0; 
    objTexture2 = TextureManager::LoadTexture(Game::pictures[pic]);
    srcR2.x = 0;
    srcR2.y = 0;
    srcR2.w = 1107;
    srcR2.h = 667;
    destR2.x = 30;
    destR2.y = 30;
    destR2.w = 750;
    destR2.h = 450;
    objTexture3 = TextureManager::loadFont("press left and right to browse down to add", color);
    srcR3.x = 0;
    srcR3.y = 0;
    srcR3.w = 800;
    srcR3.h = 30;
    destR3.x = 270;
    destR3.y = 600;
    destR3.w = 500;
    destR3.h = 30;
    teamSize = 0;
}
editScreen::~editScreen() {

}
void editScreen::handleEvents(const Uint8* keystate, bool& start, bool& edit,int* team) {
    SDL_Event event;
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_KEYDOWN:
        if (keystate[SDL_SCANCODE_RIGHT]) {
            pic++;
            if (pic == 9) {
                pic = 0;
            }
        }
        else if (keystate[SDL_SCANCODE_LEFT]) {
            pic--;
            if (pic == -1) {
                pic = 8;
            }
        }
        else if (keystate[SDL_SCANCODE_DOWN]) {
            teamSize++;
            if ( teamSize >= 5) {
                edit = false;
                start = true;
                team[teamSize - 1] = pic;
            }
            else {
                team[teamSize-1] = pic;
            }
        }
        else if (keystate[SDL_SCANCODE_RETURN]) {
            start = true;
            edit = false;
        }
        break;
    case SDL_KEYUP:
        break;
    default:
        break;
    }
}

void editScreen::update() {
    left= to_string(5-teamSize)+" left";
    objTexture1 = TextureManager::loadFont(left, "black");
    objTexture2 = TextureManager::LoadTexture(Game::pictures[pic]);
}

void editScreen::render()
{
    SDL_RenderClear(renderer);
    // this is where we put things to render
    SDL_RenderCopy(Game::renderer, objTexture1, &srcR1, &destR1);
    SDL_RenderCopy(Game::renderer, objTexture2, &srcR2, &destR2);
    SDL_RenderCopy(Game::renderer, objTexture3, &srcR3, &destR3);
    SDL_RenderPresent(renderer);
}
