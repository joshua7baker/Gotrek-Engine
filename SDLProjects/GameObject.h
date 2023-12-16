#include <SDL.h>
#include "TextureManager.h"
#pragma once
class GameObject
{
public:
	GameObject(const char* name, int x, int y, const char* filePath, SDL_Rect* clip = nullptr);
	~GameObject();

	void update();
	void render();
	
	const char* name; //Game object Name
	int x;

private:
	

	//Game objects coordinates
	int xPos;
	int yPos;

	char const* t_FilePath; //File path to load texture from

	SDL_Texture* objTexture; //Game object texture
	int t_OriginalWidth, t_OriginalHeight; // Texture height & width
	int t_ModifiedWidth, t_ModifiedHeight; // Texture height & width if modified by clipping from a sprite sheet/ image

	SDL_Rect* srcRect; //src and destination rects to use for rendering
	SDL_Rect* destRect;
};

