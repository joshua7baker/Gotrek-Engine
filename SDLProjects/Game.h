#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "TextureManager.h"
#include "Output.h"
#include "Shape.h"
#include "Viewport.h"

class Game
{
public:
	Game();
	~Game();

	bool init();
	void handleEvents();
	void render();
	void clean();
	bool running() { return isRunning; }

	SDL_Renderer* renderer;

private:
	void initError();
	bool isRunning;
	SDL_Window* gWindow;
	SDL_Surface* gScreenSurface;
};

