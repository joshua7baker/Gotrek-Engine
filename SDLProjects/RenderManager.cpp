#include "RenderManager.h"

//The render manager is a WIP class which intends to handle all render management in the future, meaning:
	// Holding all objects which need to be rendered
	// Handling all render information of objects
	// Prioritizing rendering priority based on set criterias  e.g. environment, player etc 

//This would 

//Currently object rendering is done by calling a render function on the game object class from the renderObjects function in RenderManager.cpp

RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
}

//Render all game objects in objects to render vector
void RenderManager::renderObjects(SDL_Renderer* renderer)
{
	if (!objectsToRender.empty())
	{
		for (GameObject &obj : objectsToRender)
		{
			obj.render();
		}
	}
}

//Add game object to render manager
void RenderManager::s_addObject(GameObject* objToRender)
{
	objectsToRender.push_back(*objToRender);
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
