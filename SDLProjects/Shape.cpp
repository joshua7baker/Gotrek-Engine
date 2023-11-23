#include "Shape.h"

SDL_Point dotsPoint;
SDL_Rect srcRect;

Shape::Shape(int x, int y, int w, int h)
	: xPos(x), yPos(y), width(w), height(h)
{
	srcRect.x = xPos;
	srcRect.y = yPos;
	srcRect.w = width;
	srcRect.h = height;

	dotsPoint.x = 0;
	dotsPoint.y = 0;
}

Shape::~Shape()
{
}

void Shape::drawLine(SDL_Renderer* renderer,int xStart, int yStart, int xEnd, int yEnd)
{
	SDL_RenderDrawLine(renderer, xStart, yStart, xEnd, yEnd);
}

void Shape::drawDottedLine(SDL_Renderer* renderer, int x, int y, int count, int dotSpace, eLineDirection direction)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

	//Render dotted line based on direction given
	switch (direction)
	{
	case UP:
	{
		for (int i = 0; i < count; ++i)
		{
			int dotX = x;
			int dotY = y - (i * dotSpace);

			SDL_RenderDrawPoint(renderer, dotX, dotY);
		}
		break;
	}
	case DOWN:
	{
		for (int i = 0; i < count; ++i)
		{
			int dotX = x;
			int dotY = y + (i * dotSpace);

			SDL_RenderDrawPoint(renderer, dotX, dotY);
		}
		break;
	}
	case LEFT:
	{
		for (int i = 0; i < count; ++i)
		{
			int dotX = x - (i * dotSpace);
			int dotY = y ;

			SDL_RenderDrawPoint(renderer, dotX, dotY);
		}
		break;
	}
	case RIGHT:
	{
		for (int i = 0; i < count; ++i)
		{
			int dotX = x + (i * dotSpace);
			int dotY = y;

			SDL_RenderDrawPoint(renderer, dotX, dotY);
		}
		break;
	}
	case DOWN_LEFT:
	{
		for (int i = 0; i < count; ++i)
		{
			int dotX = x - (i * dotSpace);
			int dotY = y - (i * dotSpace);

			SDL_RenderDrawPoint(renderer, dotX, dotY);
		}
		break;
	}
	case DOWN_RIGHT:
	{
		for (int i = 0; i < count; ++i)
		{
			int dotX = x + (i * dotSpace);
			int dotY = y + (i * dotSpace);

			SDL_RenderDrawPoint(renderer, dotX, dotY);
		}
		break;
	}
	case UP_LEFT:
	{
		for (int i = 0; i < count; ++i)
		{
			int dotX = x + (i * dotSpace);
			int dotY = y - (i * dotSpace);

			SDL_RenderDrawPoint(renderer, dotX, dotY);
		}
		break;

	}
	case UP_RIGHT:
	{
		for (int i = 0; i < count; ++i)
		{
			int dotX = x - (i * dotSpace);
			int dotY = y + (i * dotSpace);

			SDL_RenderDrawPoint(renderer, dotX, dotY);
		}
		break;
	}

	}
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
