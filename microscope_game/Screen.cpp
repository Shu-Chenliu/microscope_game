#include "Screen.h"
using namespace std;
const int GAME_WIDTH = 800;
const int GAME_HEIGHT = 640;
const int ARROW_WIDTH = 30;
const int ARROW_HEIGHT = 30;

Screen::Screen(SDL_Renderer* _renderer)
{
    cout << "(rendered)Screen constructor()!" << endl;

    renderer = _renderer;
}

Screen::Screen()
{
    cout << "(default)Screen constructor()!" << endl;
}

Screen::~Screen()
{
    cout << "Screen deconstrouctor()" << endl;
    delete screen;
    delete arrow;
}