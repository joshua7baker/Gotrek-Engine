#pragma once
#include <SDL.h>
class Shape
{
public:
	Shape(int x, int y, int w, int h);
	~Shape();

	void render(SDL_Renderer* renderer, bool fillRect = false);

private:
	int xPos;
	int yPos;
	int width;
	int height;

	SDL_Rect srcRect;
};

