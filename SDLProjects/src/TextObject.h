#pragma once
#include <SDL_ttf.h>
#include "Structs.h"
#include "GameObject.h"
#include "Output.h"


class TextObject
{
public:
	TextObject(const char* name, const char* textContent, int x, int y, char const* filePath);
	~TextObject();

	int getTextWidth();
	int getTextHeight();

	TextRenderData* getRenderInfo();


	const char* name;

private:

	const char* textContent;

	int xPos;
	int yPos;

	char const* t_FilePath; //File path to load texture from

	SDL_Texture* t_Texture; //Texture to render

	int t_OriginalWidth, t_OriginalHeight; // Texture height & width
	int t_ModifiedWidth, t_ModifiedHeight; // Texture height & width if modified by clipping from a sprite sheet/ image

	SDL_Rect* dest;
	TTF_Font* activeFont; // current font to render text with

	TextRenderData* renderInfo; // render data to use for rendering text

};

