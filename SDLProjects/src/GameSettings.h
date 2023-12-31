#pragma once
#include <SDL_ttf.h>

class GameSettings
{
public:
	GameSettings();
	~GameSettings();

	void setGameResolution(int x, int y);

	int* getScreenWidth();
	int* getScreenHeight();

private:
	int screenWidth;
	int screenHeight;

	TTF_Font* defaultFont;
};

