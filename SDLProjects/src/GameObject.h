#pragma once
#include <SDL.h>
#include "TextureManager.h"
#include "RenderableObject.h"
#include "Structs.h"

class GameObject : public RenderableObject
{
public:
	GameObject(const char* objectName, int x, int y, char const* filePath, SDL_Rect* clip, bool centerObj = true, SpriteSheet* spriteSheet = nullptr);
	~GameObject();

	void update();

	const char* name;

private:
	int xPos;
	int yPos;

	char const* t_FilePath;

	SDL_Texture* objTexture;
	int t_OriginalWidth, t_OriginalHeight;
	int t_ModifiedWidth, t_ModifiedHeight;

	SDL_Rect srcRect;
	SDL_Rect destRect;
};

