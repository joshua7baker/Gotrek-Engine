#pragma once
#include <SDL.h>
#include <string>

class Viewport
{
public:
	Viewport(std::string viewName, int x, int y, int width, int height);
	~Viewport();

	SDL_Rect viewport;

private:
};

