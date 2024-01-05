#pragma once
#include <SDL.h>
#include "SpriteSheet.h"

struct S_RenderData {
	SpriteSheet* spriteSheet;
	SDL_Texture* texture;
	SDL_Rect* src;
	SDL_Rect* dest;
}; 

class RenderableObject
{
public:
	RenderableObject();
	~RenderableObject();

	void setRenderInfo(SDL_Texture* tex = nullptr, SDL_Rect* src = nullptr, SDL_Rect* dest = nullptr);
	S_RenderData* getRenderData();

private:
	S_RenderData* objRenderData;
};

