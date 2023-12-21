#include "TextureManager.h"
#include "Output.h"

SDL_Renderer* TextureManager::t_Renderer = nullptr;
TTF_Font* TextureManager::gFont = nullptr;
SDL_Color* TextureManager::gColor = nullptr;


TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

bool TextureManager::setRenderer(SDL_Renderer* renderer)
{
	if (renderer != nullptr)
	{
		t_Renderer = renderer;
		return true;
	}
	else
	{
		Output::PrintMessage("Error initializing renderer in TextureManager.cpp");
		return false;
	}
}

bool TextureManager::setGlobalFont(const char* fontName, int fontSize, SDL_Color textColor)
{
	if (fontName != "" && fontName != NULL)
	{
		gFont = TTF_OpenFont(fontName, fontSize);
		if (gFont != NULL)
			return (gFont);
		else
			Output::PrintError("Error opening font.", SDL_GetError());
	}
	else
		return (false);
}

//Load texture from surface, includes optional parmeters for colorKeying 
SDL_Texture* TextureManager::loadTexture(const char* filePath, SDL_Texture* existingTexture, bool keyColor, SDL_Color color)
{
	//deallocate existing texture
	if (existingTexture != NULL)
	{
		free(existingTexture);
	}

	SDL_Surface* tempSurface{ IMG_Load(filePath) }; //create surface from filepath

	if (tempSurface != NULL)
	{
		//key colour if set to true in function call using colour values from SDL_color
		if (keyColor)
		{
			SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, color.r, color.g, color.g));
		}

		SDL_Texture* tempTexture{ SDL_CreateTextureFromSurface(t_Renderer, tempSurface) };

		if (tempTexture != NULL)
		{
			//Dealloc temp surface
			SDL_FreeSurface(tempSurface);

			return tempTexture;
		}
		else
		{
			std::cout << "Failed to load texture from surface: " << tempSurface << std::endl;
			return nullptr;
		}
	}
	else
	{
		std::cout << "Failed to load surface from file: " << tempSurface << std::endl;
		return nullptr;
	}
}

//Load TTF Text ready to render. (SDL_Color parameter may need to be changed later on to be a pointer if passing through lots of SDL_Color type variables
SDL_Texture* TextureManager::loadRenderedText(const char* textureText, SDL_Color textColor, SDL_Texture* existingTexture)
{
	if (existingTexture != NULL)
	{
		free(existingTexture);
	}
	else 
	{
		SDL_Surface* tempTextSurface{};

		//If the textColor value is not empty use it, else load with the default gColor value
		if (textColor.a != 0 || textColor.b != 0 || textColor.g != 0 || textColor.r != 0)
		{
			tempTextSurface = TTF_RenderText_Solid(gFont, textureText, textColor);
		}
		else
		{
			tempTextSurface = TTF_RenderText_Solid(gFont, textureText, *gColor);
		}

		if (tempTextSurface != NULL)
		{
			SDL_Texture* tempTextTexture = SDL_CreateTextureFromSurface(t_Renderer, tempTextSurface);
			SDL_FreeSurface(tempTextSurface);
			
			if (tempTextTexture != NULL)
			{
				return tempTextTexture;
			}
			else
			{
				Output::PrintMessage("Error loading Rendered Text Texture, tempTextTexture cannont be null");
				return nullptr;
			}
		}
	}
}

void TextureManager::free(SDL_Texture* existingTexture)
{
	if (existingTexture != NULL)
	{
		SDL_DestroyTexture(existingTexture);
		existingTexture = NULL;
	}
}

void TextureManager::freeFont(TTF_Font* fontToFree)
{
	if (fontToFree != NULL)
	{
		TTF_CloseFont(fontToFree);
	}
	else
		Output::PrintError("SDL error failed to dispose of Font. SDL Error:", SDL_GetError());
}

//Colour modulate the current TextureManager
void TextureManager::setColour(SDL_Texture* texture, Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(texture, red, green, blue);
}

//Set blending function
void TextureManager::setBlendMode(SDL_Texture* texture, SDL_BlendMode blending)
{

	SDL_SetTextureBlendMode(texture, blending);
}

//Set alpha (opaccity) function
void TextureManager::setAlpha(SDL_Texture* texture, Uint8 alpha)
{
	SDL_SetTextureAlphaMod(texture, alpha);
}

//render single texture to screen
void TextureManager::render(SDL_Texture* texture, int x, int y, SDL_Rect* src, SDL_Rect* dest, int t_OriginalWidth, int t_OriginalHeight)
{
	SDL_RenderCopy(t_Renderer, texture, src, dest);
}

//return texture height
int TextureManager::getHeight(SDL_Texture* texture)
{
	int texHeight{ 0 };
	if (SDL_QueryTexture(texture, nullptr, nullptr, nullptr, &texHeight) == 0)
	{
		return texHeight;
	}
	else
		Output::PrintError("Error occured getting Texture Height: ", SDL_GetError());
		return 0;
}

//return texture width
int TextureManager::getWidth(SDL_Texture* texture)
{
	int texWidth{ 0 };
	if (SDL_QueryTexture(texture, nullptr, nullptr, &texWidth, nullptr) == 0)
	{
		return texWidth;
	}
	else
		Output::PrintError("Error occured getting Texture Width: ", SDL_GetError());
	return 0;
}
