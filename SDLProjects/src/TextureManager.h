#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>
#include <vector>
#include "Output.h"

//Texture manager currently handles .png texture and TTF image loading, this could later be categorized using namespaces.

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	//set renderer to be used for all rendering functionality in the TextureManager
	static bool setRenderer(SDL_Renderer* renderer);
	static bool setGlobalFont(const char* fontName, int fontSize, SDL_Color textColor);

	//Load img from specified path
	static SDL_Texture* loadTexture(const char* filename, SDL_Texture* existingTexture = nullptr, bool keyColour = false, SDL_Color color = {0,0,0});

	//Load text to render using SDL2_ttf
	static SDL_Texture* loadRenderedText(const char* textureText = nullptr, SDL_Color textColor = {0,0,0,0}, SDL_Texture* existingTexture = nullptr);

	//Deallocate texture
	static void free(SDL_Texture* existingTexture);
	static void freeFont(TTF_Font* fontToFree);


	//Set color modulation
	static void setColour(SDL_Texture* texture, Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	static void setBlendMode(SDL_Texture* texture, SDL_BlendMode blending);

	//Set alpha modulation
	static void setAlpha(SDL_Texture* texture, Uint8 alpha);

	//Draw texture to screen
	static void render(SDL_Texture* texture, int x = 0, int y = 0, SDL_Rect* src = NULL, SDL_Rect* dest = NULL, int t_OriginalWidth = 0, int t_OriginalHeight = 0);
	void renderMany(SDL_Renderer* renderer, SDL_Rect* src, std::vector<SDL_Rect> spriteSheet);
	
	//Get image dimensions
	static int getHeight(SDL_Texture* texture) ;
	static int getWidth(SDL_Texture* texture);


private:
	static SDL_Renderer* t_Renderer;
	static TTF_Font* gFont;
	static int* gTextSize;
	static SDL_Color* gColor;

};

