#pragma once
#include <SDL.h>

//Hold object rendering data when attempting to render Texture to a window.
struct RenderData {
	SDL_Texture* texture;
	SDL_Rect* src;
	SDL_Rect* dest;
};
