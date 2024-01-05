#include "RenderManager.h"

SDL_Renderer* RenderManager::s_renderer = nullptr;

RenderManager::RenderManager(SDL_Renderer* renderer)
{
	setRenderer(renderer);
}

RenderManager::~RenderManager()
{
}

//Set s_renderer upon class construction
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

//Render all game objects in objects to render vector
void RenderManager::renderObjects()
{
	if (!objectsToRender.empty())
	{
		for (GameObject &obj : objectsToRender)
		{
			renderGameObject(&obj);
		};
	}
}

void RenderManager::renderText(TextRenderData* textRenderInfo)
{
	SDL_RenderCopy(s_renderer, textRenderInfo->texture, nullptr, textRenderInfo->dest);
}

//Turn parameters into pointers & pass by refs to not copy data over every render call
//Decouple object render between RenderMan & GameObject to render the obj from here instantly,
//opposed to calling obj.render from rendermanager to gameobject.cpp then back to RenderManager which is what currently happens

//Change input parameter type to use RenderData so the function can be utilized for various rendering requirements
void RenderManager::renderGameObject(GameObject* objToRender)
{
	RenderData* tempRenderData = objToRender->getRenderData();

	if (s_renderer != nullptr)
	{
		if (tempRenderData != nullptr && tempRenderData->texture != nullptr)
		{
			SDL_RenderCopy(s_renderer, tempRenderData->texture, tempRenderData->src, tempRenderData->dest);
		}
		else 
			Output::PrintMessage("Error rendering copy of GameObject, RenderData cannot be null and must have a Texture");
	}
	else 
		Output::PrintMessage("Error getting rendering GameObject, s_renderer cannot be null");
}

//Change input parameter type to use RenderData so the function can be utilized for various rendering requirements
void RenderManager::renderButtonObject(RenderableObject* objToRender)
{
	S_RenderData* tempRenderData = objToRender->getRenderData();

	if (s_renderer != nullptr)
	{
		if (tempRenderData != nullptr && tempRenderData->texture != nullptr)
		{
			SDL_RenderCopy(s_renderer, tempRenderData->texture, tempRenderData->src, tempRenderData->dest);
		}
		else
			Output::PrintMessage("Error rendering copy of GameObject, RenderData cannot be null and must have a Texture");
	}
	else
		Output::PrintMessage("Error getting rendering GameObject, s_renderer cannot be null");
}


//Add game object to render to vector
void RenderManager::addObject(GameObject* objToRender)
{
	objectsToRender.push_back(*objToRender);
}

//Remove game object from vector list of objects to render
void RenderManager::removeObject(GameObject &objToRender)
{
	//Requires setup of operator inside GameObj class for comparisons
	//objectsToRender.erase(std::remove(objectsToRender.begin(), objectsToRender.end(), objectsToRender.begin()));
}
