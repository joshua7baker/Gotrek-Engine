#include "Texture.h"

Texture::Texture()
{
	texture = nullptr;
	tWidth = 0;
	tHeight = 0;
}

Texture::~Texture()
{
	free();
}

//Pass in file name of asset to load texture
bool Texture::loadTexture(SDL_Renderer* renderer, const char* filePath)
{
	//deallocate existing texture
	if (texture != NULL)
	{
		free();
	}

	SDL_Surface* tempSurface{ IMG_Load(filePath) };

	if (tempSurface != NULL)
	{
		SDL_Texture* tempTexture{ SDL_CreateTextureFromSurface(renderer, tempSurface) };


		if (tempTexture != NULL)
		{
			tWidth = tempSurface->w;
			tHeight = tempSurface->h;

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

void Texture::free()
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		tWidth = 0;
		tHeight = 0;
	}
}

//render texture to screen
void Texture::render(SDL_Renderer* renderer, int x, int y)
{
	SDL_Rect renderQuad{ x, y, tWidth, tHeight };
	SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
}

int Texture::getHeight()
{
	return tHeight;
}

int Texture::getWidth()
{
	return tWidth;
}
