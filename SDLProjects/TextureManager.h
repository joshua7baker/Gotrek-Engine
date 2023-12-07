#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "Output.h"

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	//set renderer to be used for all rendering functionality in the TextureManager
	static bool setRenderer(SDL_Renderer* renderer);

	//Load img from specified path
	static SDL_Texture* loadTexture(const char* filename, SDL_Texture* existingTexture = nullptr, bool keyColour = false, SDL_Color color = {0,0,0});

	//Deallocate texture
	static void free(SDL_Texture* existingTexture);

	//Set color modulation
	static void setColour(SDL_Texture* texture, Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	static void setBlendMode(SDL_Texture* texture, SDL_BlendMode blending);

	//Set alpha modulation
	static void setAlpha(SDL_Texture* texture, Uint8 alpha);

	//Draw texture to screen
	static void render(SDL_Texture* texture, int x, int y, SDL_Rect* src = NULL, SDL_Rect* dest = NULL, int t_Width = 0, int t_Height = 0);
	void render(SDL_Renderer* renderer, SDL_Rect* src, std::vector<SDL_Rect> spriteSheet);
	
	//Get image dimensions
	int getHeight(SDL_Texture* texture) ;
	int getWidth(SDL_Texture* texture);


private:
	static SDL_Renderer* t_Renderer;
};

