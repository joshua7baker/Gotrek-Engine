#include "GameObject.h"

GameObject::GameObject(const char* objectName, int x, int y, char const* filePath, SDL_Rect* clip, bool centerObj, SpriteSheet* spriteSheet)
	: name(objectName), xPos(x), yPos(y), t_FilePath(filePath)
{
	 objTexture = TextureManager::loadTexture(t_FilePath);
	 
	 t_OriginalHeight = 0;
	 t_OriginalWidth = 0;
	 t_ModifiedWidth = 0;
	 t_ModifiedHeight = 0;

	 if (objTexture != nullptr)
	 {
		 setRenderTexture(objTexture); 
		 t_OriginalWidth = TextureManager::getWidth(objTexture);
		 t_OriginalHeight = TextureManager::getHeight(objTexture);
	 }

	 if (spriteSheet != nullptr)
		 setSpriteSheet(spriteSheet);

	 if (objTexture != nullptr)

	 if (clip != NULL)
	 {
		 t_ModifiedWidth = clip->w;
		 t_ModifiedHeight = clip->h;

		 srcRect.x = clip->x;
		 srcRect.y = clip->y;
		 srcRect.w = clip->w;
		 srcRect.h = clip->h;
	 }
	 else
	 {
		 srcRect.x = 0;
		 srcRect.y = 0;
		 srcRect.w = t_OriginalWidth;
		 srcRect.h = t_OriginalHeight;
	 }
	 
	 if (centerObj)
	 {
		 //dest rec x & y centralize the texture render location to the xPos & yPos by deducting x & y by half the texture width & height taken away from the base coords
		 destRect.x = { xPos - (srcRect.w / 2) };
		 destRect.y = { yPos - (srcRect.h / 2) };
		 destRect.w = srcRect.w;
		 destRect.h = srcRect.h;
	 }

	 setRenderSrcRect(srcRect);
	 setRenderDest(destRect);
}

GameObject::~GameObject(){
}

void GameObject::update(){
}