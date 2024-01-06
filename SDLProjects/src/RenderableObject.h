#pragma once
#include <SDL.h>
#include <vector>
#include "SpriteSheet.h"

struct S_RenderData {
	SDL_Texture* texture;
	SDL_Rect* src;
	SDL_Rect* dest;
}; 

class RenderableObject
{
public:
	RenderableObject();
	~RenderableObject();

	virtual S_RenderData* getRenderData();

	void setRenderData(SDL_Texture* tex, SDL_Rect* src, SDL_Rect* dest);
	void setSpriteSheet(SpriteSheet* spriteSheet);
	void setSpriteSheetSrcRect(int x = -1 );
	void setRenderSrcRect(SDL_Rect&src);
	void setRenderDest(SDL_Rect &dest);
	void setRenderTexture(SDL_Texture* tex);

	std::vector<SDL_Rect>* setSpriteVector(SpriteSheet* spriteSheet);

private:
	std::vector<SDL_Rect> spriteSheetRects;
	S_RenderData* objRenderData;
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

protected:
};



