#include "TextureManager.h"

TextureManager::TextureManager()
{
	texture = NULL;
	texWidth = 0;
	texHeight = 0;
}

TextureManager::~TextureManager()
{
	free();
}

//Pass in file name of asset to load texture
bool TextureManager::loadTexture(SDL_Renderer* renderer, const char* filePath, bool colourKey)
{
	//deallocate existing texture
	if (texture != NULL)
	{
		free();
	}

	SDL_Surface* tempSurface{ IMG_Load(filePath) };

	if (tempSurface != NULL)
	{
		if (colourKey == true)
		{
			SDL_SetColorKey(tempSurface, true, SDL_MapRGB(tempSurface->format, 0, 0xFF, 0xFF));
		}

		SDL_Texture* tempTexture{ SDL_CreateTextureFromSurface(renderer, tempSurface) };


		if (tempTexture != NULL)
		{
			texWidth = tempSurface->w;
			texHeight = tempSurface->h;

			//Dealloc old loaded surface
			SDL_FreeSurface(tempSurface);

			texture = tempTexture;
			return texture != NULL;
		}
		else
		{
			std::cout << "Failed to load texture from surface: " << tempSurface << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "Failed to load surface from file: " << texture << std::endl;
		return false;
	}
}

void TextureManager::free()
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		texWidth = 0;
		texHeight = 0;
	}
}

//render texture to screen
void TextureManager::render(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* src, SDL_Rect* target)
{
	SDL_RenderCopy(renderer, texture, src, target);
}

int TextureManager::getHeight()
{
	return 0;
}

int TextureManager::getWidth()
{
	return 0;
}
