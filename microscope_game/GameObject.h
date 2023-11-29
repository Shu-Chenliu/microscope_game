#pragma once
#include "game.h"
class GameObject
{
public:
	GameObject(const char* texturesheet,int x,int y,int w,int h);
	GameObject(const char* texturesheet, int x, int y,int srcx,int srcy, int w, int h);
	GameObject(const char* textureSheet, int x, int y, int w, int h, double ww, double hh);
	GameObject(int money, int x, int y, int w, int h,const char* color);
	GameObject(const char* sign, int x, int y, int w, int h, const char* color);
	~GameObject();
	virtual void update();
	void update(int money);
	virtual void render();
	int getxpos() {
		return xpos;
	}
	int getypos() {
		return ypos;
	}
	void setxpos(int x) {
		xpos = x;
	}
	void setypos(int y) {
		ypos = y;
	}
protected:
	int xpos;
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcR, destR;
};

