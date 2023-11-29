#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	//Load img from specified path
	bool loadTexture(SDL_Renderer* renderer, const char* filename, bool colourKey);

	//Deallocate texture
	void free();

	//Render
	void render(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* src, SDL_Rect* target);

	//void colourKeyImage(SDL_Surface* surface, int flags, Uint32 key);

	//Gets image dimensions
	int getHeight();
	int getWidth();

private:
	SDL_Texture* texture;

	int texWidth;
	int texHeight;
};

