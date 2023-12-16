#pragma once
#include <vector>
#include "GameObject.h"
#include "Structs.h"

class RenderManager
{
public:
	RenderManager(SDL_Renderer* renderer);
	~RenderManager();

	//set renderer to be used for all rendering functionality in the RenderManager. 
	//this may need to change later to accomodate multiple renderers for multiple windows if the need arises.
	static bool setRenderer(SDL_Renderer* renderer);
	
	//render objects within objectsToRender list. This should contain all entities which should be rendered to the current window.
	void renderObjects(SDL_Renderer* renderer); //Call object to render from list

	//render objects to screen (mainly called within GameObject.cpp)
	void renderObject(GameObject* objToRender);

	void addObject(GameObject* objToRender); //Add game object to vector list of objects to be rendered to screen.
	void removeObject(GameObject &objToRender); //Remove game object from vector list of objects to be rendered to screen.


private:
	std::vector<GameObject> objectsToRender;
	static SDL_Renderer* s_renderer;
};

