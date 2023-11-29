#pragma once
#include "game.h"
#include "SDL_ttf.h"
class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* filename);//load picture
	static SDL_Texture* loadFont(const string& text, const char* color);//load ttf
};

