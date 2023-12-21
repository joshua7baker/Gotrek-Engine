#include "GameSettings.h"

GameSettings::GameSettings()
{
	screenWidth = 0;
	screenHeight = 0;
}

GameSettings::~GameSettings()
{
}

void GameSettings::setGameResolution(int x, int y)
{
	screenWidth = x;
	screenHeight = y;
}

int* GameSettings::getScreenWidth()
{
	return &screenWidth;
}

int* GameSettings::getScreenHeight()
{
	return &screenHeight;
}
