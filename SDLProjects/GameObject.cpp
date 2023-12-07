#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* name, int x, int y, char const* filePath)
	: name(name), xPos(x), yPos(y), t_FilePath(filePath)
{
	 TextureManager::loadTexture(t_FilePath);
}

GameObject::~GameObject()
{
}

void GameObject::render(SDL_Renderer* renderer)
{
}

void GameObject::update()
{
}


