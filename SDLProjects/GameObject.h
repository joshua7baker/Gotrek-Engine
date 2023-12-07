#include <SDL.h>
#include "TextureManager.h"
#pragma once
class GameObject
{
public:
	GameObject(const char* name, int x, int y, const char* filePath);
	~GameObject();

	void update();
	void render(SDL_Renderer* renderer);

private:
	const char* name;
	int xPos;
	int yPos;
	char const* t_FilePath;

	SDL_Texture* objTexture;
	int t_Width, t_Height;

	SDL_Rect srcRect, destRect;
};

