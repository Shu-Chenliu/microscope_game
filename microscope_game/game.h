#pragma once
#include <iostream>
#include <string>
#include "SDL.h"
using namespace std;
class Game
{
private:
	bool isRunning;
	bool isStart = true;
	bool isEdit=false;
	int count;
	SDL_Window* window;
	int team[5] = { 0,1,2,3,4 };
	int ourhomeBlood = 1000;
	int enemyhomeBlood = 1000;
	int t = 0;

public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvent();
	void update();
	void render();
	void clean();
	bool running();
	bool startMode() {
		return isStart;
	}
	void displayStartScreen();
	bool editMode() {
		return isEdit;
	}
	void loadpicture();
	void displayEditScreen();
	void end();
	static SDL_Renderer* renderer;
	SDL_Texture* objTexture1 = nullptr;
	SDL_Rect srcR, destR;
	static const char* pictures[9];
	static const char* playerpic[9];
	static const char* enemypic[5];
};

