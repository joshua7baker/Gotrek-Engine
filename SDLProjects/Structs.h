#pragma once
#include <SDL.h>

struct RenderData {
	SDL_Texture* texture;
	SDL_Rect* src;
	SDL_Rect* dest;
};
