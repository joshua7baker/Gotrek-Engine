#pragma once
#include "Game.h"
#include <iostream>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* filename);
	void draw(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* src, SDL_Rect* target);

private:
};

