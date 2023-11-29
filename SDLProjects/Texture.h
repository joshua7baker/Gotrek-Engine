#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Texture
{
public:
	Texture();
	~Texture();

	//Load img from specified path
	bool loadTexture(SDL_Renderer* renderer, const char* filename);

	//Deallocate texture
	void free();

	//Render
	void render(SDL_Renderer* renderer, int x, int y);

	//void colourKeyImage(SDL_Surface* surface, int flags, Uint32 key);

	//Gets image dimensions
	int getHeight();
	int getWidth();

private:
	SDL_Texture* texture;

	int tWidth;
	int tHeight;
};

