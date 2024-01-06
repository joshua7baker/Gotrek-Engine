#include "RenderManager.h"

SDL_Renderer* RenderManager::s_renderer = nullptr;

RenderManager::RenderManager(SDL_Renderer* renderer)
{
	setRenderer(renderer);
}

RenderManager::~RenderManager()
{
}

bool RenderManager::setRenderer(SDL_Renderer* renderer)
{
	if (renderer != NULL)
	{
		s_renderer = renderer;
		return true;
	}
	else
	{
		Output::PrintMessage("Error setting s_renderer in RenderManager, renderer = cannot be null");
		return false;
	}
}

void RenderManager::renderObjects()
{
	//Future note to setup rendering priority system

	//Render Game Objects
	if (!gameObjectsToRender.empty())
	{
		for (GameObject &obj : gameObjectsToRender)
		{
			renderObject(&obj);
		};
	}
	//Render Buttons
	if (!buttonsToRender.empty())
	{
		for (RenderableObject& obj : buttonsToRender)
		{
			renderObject(&obj);
		}
	}
}

void RenderManager::renderObject(RenderableObject* objToRender)
{
	S_RenderData tempRenderData = *objToRender->getRenderData();

	if (s_renderer != nullptr)
	{
		if (tempRenderData.texture != nullptr)
		{
			SDL_RenderCopy(s_renderer, tempRenderData.texture, tempRenderData.src, tempRenderData.dest);
		}
		else 
			Output::PrintMessage("Error rendering copy of GameObject, RenderData cannot be null and must have a Texture");
	}
	else 
		Output::PrintMessage("Error getting rendering GameObject, s_renderer cannot be null");
}

void RenderManager::renderTextObject(TextRenderData* textRenderInfo)
{
	SDL_RenderCopy(s_renderer, textRenderInfo->texture, nullptr, textRenderInfo->dest);
}

//Add game object to render to vector list
void RenderManager::addObject(GameObject* objToRender)
{
	gameObjectsToRender.push_back(*objToRender);
}

//Remove game object from vector list of objects to render
void RenderManager::removeObject(GameObject &objToRender)
{
	//Requires setup of operator inside GameObj class for comparisons
	//gameObjectsToRender.erase(std::remove(gameObjectsToRender.begin(), gameObjectsToRender.end(), gameObjectsToRender.begin()));
}
