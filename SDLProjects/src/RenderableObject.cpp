#include "RenderableObject.h"
#include "Output.h"

RenderableObject::RenderableObject()
{
	objRenderData = new S_RenderData{};
}

RenderableObject::~RenderableObject()
{
	delete objRenderData;
}

void RenderableObject::setRenderInfo(SDL_Texture* tex, SDL_Rect* src, SDL_Rect* dest)
{
	objRenderData->texture = tex;
	objRenderData->src = src;
	objRenderData->dest = dest;
}

S_RenderData* RenderableObject::getRenderData()
{
	if (objRenderData != nullptr)
		return objRenderData;
	else 
	{
		Output::PrintMessage("getRenderInfo returned nullptr as objRenderData was NULL");
		return nullptr;
	}
}

