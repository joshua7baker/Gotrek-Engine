#include "Shape.h"

SDL_Rect srcRect;

Shape::Shape(int x, int y, int w, int h)
	: xPos(x), yPos(y), width(w), height(h)
{
	srcRect.x = xPos;
	srcRect.y = yPos;
	srcRect.w = width;
	srcRect.h = height;
}

Shape::~Shape()
{
}

void Shape::render(SDL_Renderer* renderer, bool fillRect)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	if (fillRect)
	{
		SDL_RenderFillRect(renderer, &srcRect);
	}
	else
		SDL_RenderDrawRect(renderer, &srcRect);
}
