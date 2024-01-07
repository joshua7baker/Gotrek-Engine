#pragma once
#include <SDL_ttf.h>
#include "RenderableObject.h"
#include "Output.h"

class TextObject : public RenderableObject
{
public:
	TextObject(const char* name, const char* textContent, int x, int y, char const* fontFilePath = nullptr);
	~TextObject();

	void setTextContent(const char* newText);

	int getTextWidth();
	int getTextHeight();
	 
	const char* name;

private:
	const char* textContent;

	int xPos;
	int yPos;

	char const* t_FilePath; //File path to load texture from

	SDL_Texture* t_Texture; //Texture to render

	int t_OriginalWidth, t_OriginalHeight; // Texture height & width
	int t_ModifiedWidth, t_ModifiedHeight; // Texture height & width if modified by clipping from a sprite sheet/ image

	SDL_Rect destRect;
	TTF_Font* activeFont; // current font to render text with
};

