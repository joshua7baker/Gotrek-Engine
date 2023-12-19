#pragma once
#include <SDL.h>
#include "TextureManager.h"
#include "Structs.h"

class GameObject
{
public:
	GameObject(const char* name, int x, int y, const char* filePath, SDL_Rect* clip = nullptr);
	~GameObject();

	void update();

	RenderData* getRenderData(); //Get rendering info (called from RenderManager)

	const char* name; //Game object Name

private:
	int xPos; //Game Object X Coordinate
	int yPos; //Game Object Y Coordinate

	char const* t_FilePath; //File path to load texture from

	SDL_Texture* objTexture; //Game object texture
	int t_OriginalWidth, t_OriginalHeight; // Texture height & width
	int t_ModifiedWidth, t_ModifiedHeight; // Texture height & width if modified by clipping from a sprite sheet/ image

	SDL_Rect* srcRect; //src rect to use for rendering
	SDL_Rect* destRect;//dest rect to use for rendering

	RenderData objRenderInfo; //Render info to be passed to RenderManager
};

