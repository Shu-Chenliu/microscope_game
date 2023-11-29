#include "GameObject.h"
#include "TextureManager.h"
#include <string.h>
GameObject::GameObject(const char* texturesheet, int x, int y, int w, int h) {
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	srcR.h = h;
	srcR.w = w;
	srcR.x = 250;
	srcR.y = 250;
	destR.x = xpos;
	destR.y = ypos;
	destR.w = srcR.w;
	destR.h = srcR.h;
}
GameObject::GameObject(const char* texturesheet, int x, int y,int srcx,int srcy, int w, int h) {
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	srcR.h = h;
	srcR.w = w;
	srcR.x = srcx;
	srcR.y = srcy;
	destR.x = xpos;
	destR.y = ypos;
	destR.w = srcR.w*0.5;
	destR.h = srcR.h*0.5;
}
GameObject::GameObject(const char* textureSheet, int x, int y, int w, int h,double ww,double hh) {
	objTexture = TextureManager::LoadTexture(textureSheet);
	xpos = x;
	ypos = y;
	srcR.h = h;
	srcR.w = w;
	srcR.x = 0;
	srcR.y = 0;
	destR.x = xpos;
	destR.y = ypos;
	destR.w = srcR.w*ww;
	destR.h = srcR.h*hh;
}
GameObject::GameObject(int money, int x, int y, int w, int h,const char* color) {
	string moneyString = to_string(money);
	objTexture = TextureManager::loadFont(moneyString,color);
	xpos = x;
	ypos = y;
	srcR.h = h;
	srcR.w = w;
	srcR.x = 0;
	srcR.y = 0;
	destR.x = xpos;
	destR.y = ypos;
	destR.w = srcR.w ;
	destR.h = srcR.h;
}
GameObject::GameObject(const char* sign, int x, int y, int w, int h, const char* color) {
	objTexture = TextureManager::loadFont(sign, color);
	xpos = x;
	ypos = y;
	srcR.h = h;
	srcR.w = w;
	srcR.x = 0;
	srcR.y = 0;
	destR.x = xpos;
	destR.y = ypos;
	destR.w = srcR.w;
	destR.h = srcR.h;
}
GameObject::~GameObject() {

}
void GameObject::update() {
	destR.x = xpos;
	destR.y = ypos;
}
void GameObject::update(int count) {
	objTexture = TextureManager::loadFont(to_string(count), "black");
}
void GameObject::render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcR, &destR);
}
