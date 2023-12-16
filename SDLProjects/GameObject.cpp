#include "GameObject.h"
#include "TextureManager.h"
#include "RenderManager.h"

GameObject::GameObject(const char* name, int x, int y, char const* filePath, SDL_Rect* clip)
	: name(name), xPos(x), yPos(y), t_FilePath(filePath)
{
	//Load and initialize texture data for the game object
	
	 objTexture = TextureManager::loadTexture(t_FilePath);
	 t_OriginalWidth = TextureManager::getWidth(objTexture);
	 t_OriginalHeight = TextureManager::getHeight(objTexture);
	 t_ModifiedWidth = 0;
	 t_ModifiedHeight = 0;

	 srcRect = new SDL_Rect();
	 destRect = new SDL_Rect();

	 if (clip != NULL)
	 {
		 t_ModifiedWidth = clip->w;
		 t_ModifiedHeight = clip->h;

		 //Initialize src and destination rects for rendering and positioning data
		 srcRect->x = clip->x;
		 srcRect->y = clip->y;
		 srcRect->w = clip->w;
		 srcRect->h = clip->h;
	 }
	 else
	 {
		 //Initialize src and destination rects for rendering and positioning data
		 srcRect->x = 0;
		 srcRect->y = 0;
		 srcRect->w = t_OriginalWidth;
		 srcRect->h = t_OriginalHeight;
	 }
	 //dest rec x & y centralize the texture render location to the xPos & yPos by deducting x & y by half the texture width & height taken away from the base coords
 	 destRect->x = { xPos - (srcRect->w / 2) };
	 destRect->y = { yPos - (srcRect->h / 2) };
	 destRect->w = srcRect->w;
	 destRect->h = srcRect->h;

	 //RenderManager::addObject(this);
}

GameObject::~GameObject(){
}

void GameObject::render()
{
	if (objTexture != NULL)
		TextureManager::render(objTexture, xPos, yPos, srcRect, destRect, t_OriginalWidth, t_OriginalHeight);
	else
		Output::PrintMessage("Failed to call render function inside GameObject.cpp, objTexture was null");
}

void GameObject::update(){
}


