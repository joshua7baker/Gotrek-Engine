#include <SDL.h>
#include <vector>
#include <string>
#pragma once
class SpriteSheet
{
public:
	SpriteSheet(const char* texName);
	~SpriteSheet();

	std::vector<SDL_Rect>* getSprites();
	const char* getTextureName();

	std::vector<SDL_Rect> spriteSheet;

private:
	const char* sheetName;
};

