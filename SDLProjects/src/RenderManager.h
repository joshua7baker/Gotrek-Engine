#pragma once
#include <vector>
#include "GameObject.h"
#include "Button.h"
#include "Structs.h"

class RenderManager
{
public:
	RenderManager(SDL_Renderer* renderer);
	~RenderManager();

	static bool setRenderer(SDL_Renderer* renderer);
	
	void renderObjects();

	void renderObject(RenderableObject* objToRender);
	void renderTextObject(TextRenderData* textRenderInfo);

	void addObject(GameObject* objToRender); //Add game object to vector list of objects to be rendered to screen.
	void removeObject(GameObject &objToRender); //Remove game object from vector list of objects to be rendered to screen.


private:
	std::vector<GameObject> gameObjectsToRender;
	std::vector<RenderableObject> buttonsToRender;

	static SDL_Renderer* s_renderer;
};

