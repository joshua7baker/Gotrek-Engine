#include "RenderableObject.h"
#include "Output.h"

RenderableObject::RenderableObject()
{
	texture = nullptr;
	srcRect.x = { 0 };
	srcRect.y = { 0 };
	srcRect.w = { 0 };
	srcRect.h = { 0 };

	destRect.x = { 0 };
	destRect.y = { 0 };
	destRect.w = { 0 };
	destRect.h = { 0 };

	objRenderData = new S_RenderData{ texture, &srcRect, &destRect };

	spriteSheetRects = std::vector<SDL_Rect>();
}

RenderableObject::~RenderableObject() {
	delete objRenderData;
}

void RenderableObject::setRenderData(SDL_Texture* tex, SDL_Rect* src, SDL_Rect* dest)
{
	objRenderData->texture = tex;
	objRenderData->src = src;
	objRenderData->dest = dest;
}

void RenderableObject::setSpriteSheet(SpriteSheet* spriteSheet)
{
	if (spriteSheet != nullptr)
		spriteSheetRects = *spriteSheet->getSprites();
}

void RenderableObject::setSpriteSheetSrcRect(int index)
{
	if (index >= 0)
	{
		srcRect = spriteSheetRects[index];
	}
}

void RenderableObject::setRenderSrcRect(SDL_Rect &src)
{
	srcRect = src;
}

void RenderableObject::setRenderDest(SDL_Rect &dest)
{
	destRect = dest;
}

void RenderableObject::setRenderTexture(SDL_Texture* tex)
{
	if (tex != nullptr)
		texture = tex;
}

std::vector<SDL_Rect>* RenderableObject::setSpriteVector(SpriteSheet* spriteSheet)
{
	if (spriteSheet != NULL)
	{
		return spriteSheet->getSprites();
	}
	return nullptr;
}

S_RenderData* RenderableObject::getRenderData()
{
	if (objRenderData != nullptr)
	{
		setRenderData(texture, &srcRect, &destRect);
		return objRenderData;
	}
	else
	{
		Output::PrintMessage("getRenderInfo returned nullptr as objRenderData was NULL");
		return nullptr;
	}
}

