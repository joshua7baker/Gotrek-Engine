#pragma once
#include <vector>
#include "GameObject.h"
class RenderManager
{
public:
	RenderManager();
	~RenderManager();

	void renderObjects(SDL_Renderer* renderer);

	void s_addObject(GameObject* objToRender); //Add game object to vector list of objects to be rendered

	void addObject(GameObject* objToRender); //Add game object to vector list of objects to be rendered
	void removeObject(GameObject &objToRender); //Remove game object from vector list of objects to be rendered

private:
	std::vector<GameObject> objectsToRender;
};

