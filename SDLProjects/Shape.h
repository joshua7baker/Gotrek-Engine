#pragma once
#include <SDL.h>
class Shape
{
public:
	Shape(int x, int y, int w, int h);
	~Shape();

	enum eLineDirection {
		UP,
		DOWN,
		LEFT,
		RIGHT,
		DOWN_LEFT,
		DOWN_RIGHT,
		UP_LEFT,
		UP_RIGHT
	};

	void drawLine(SDL_Renderer* renderer, int xStart, int yStart, int xEnd, int yEnd);
	void drawDottedLine(SDL_Renderer* renderer, int x, int y, int count, int dotSpace, eLineDirection direction);
	void drawDottedLineShape(SDL_Renderer* renderer, SDL_Point* points, int count);

	//rendering
	void render(SDL_Renderer* renderer, bool fillRect = false);

private:
	int xPos;
	int yPos;
	int width;
	int height;

	SDL_Point dotsPoint;
	SDL_Rect srcRect;
};

