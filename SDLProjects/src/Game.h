#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "TextureManager.h"
#include "Output.h"
#include "Viewport.h"
#include "RenderManager.h"
#include "GameSettings.h"
#include "Timer.h"

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
	RenderManager* renderManager;
	GameSettings* gameSettings;

	int screenWidth;
	int screenHeight;
};

