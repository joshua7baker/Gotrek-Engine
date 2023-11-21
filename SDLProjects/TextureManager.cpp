#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

//Pass in file name of asset to load texture
SDL_Texture* TextureManager::LoadTexture(SDL_Renderer* renderer, const char* texture)
{
	SDL_Surface* tempSurface{ IMG_Load(texture) };
	
	if (tempSurface != NULL)
	{
		SDL_Texture* tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
		SDL_FreeSurface(tempSurface);

		if (tempTexture != NULL)
		{
			return tempTexture;
		}
		else
		{
			std::cout << "Failed to load texture from surface: " << tempSurface << std::endl;
			return NULL;
		}
	}
	else
		std::cout << "Failed to load surface from file: " << texture << std::endl;
		return NULL;
}

//Render texture to screen
void TextureManager::Draw(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* src, SDL_Rect* target)
{
	SDL_RenderCopy(renderer, texture, src, target);
}
