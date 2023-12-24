#include "TextureManager.h"
#include "Output.h"

SDL_Renderer* TextureManager::t_Renderer = nullptr;
const char* TextureManager::defaultFont = nullptr;
int TextureManager::defaultFontSize{ 0 };
SDL_Color TextureManager::defaultColor {};
SDL_Color TextureManager::nullColor{};

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

bool TextureManager::setDefaultFont(const char* fontName, int fontSize, SDL_Color textColor)
{
	bool fontValid{true};

	if (fontName != "" && fontName != NULL)
	{
		defaultFont = fontName;
	}
	else
	{
		Output::PrintMessage("Default font not assigned, fontName cannot be null or empty");
		fontValid = false;
	}

	if (fontSize != 0)
	{
		defaultFontSize = fontSize;
	}
	else
	{
		Output::PrintMessage("Default font size not assigned, fontSize cannot must be greater than 0");
		fontValid = false;
	}

	if ((textColor.r <= 255 && textColor.r >= 0) && (textColor.g <= 255 && textColor.g >= 0) && (textColor.b <= 255 && textColor.b >= 0) && (textColor.a <= 255 && textColor.a >= 0))
	{
		defaultColor = textColor;
	}
	else
	{
		Output::PrintMessage("Default color not assigned, color value out of range, must be between 0-255");
		fontValid = false;
	}

	if (fontValid)
		return fontValid;
	else
	{
		Output::PrintMessage("Failed to assign default font texture values. See output log for more details.");
		return false;
	}
}

const char* TextureManager::getDefaultFont()
{
	return nullptr;
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
SDL_Texture* TextureManager::loadRenderedText(const char* textureText, const char* fontToUse, int* fontSize, SDL_Color* textColor, SDL_Texture* existingTexture)
{
	if (existingTexture != NULL)
	{
		free(existingTexture);
	}

	const char* tempFontPath{ (fontToUse != NULL && fontToUse != "") ? fontToUse : defaultFont}; //Check if specific font was defined to be used, else use the default set font
	int tempFontSize { (fontSize != NULL) ? *fontSize : defaultFontSize }; // Check if specific font size was defined to be used, else use the default set font size
		
	SDL_Color tempColor{};

	//Compare memory blocks to identify whether the values at each block are the same or different to determine whether to use the default color or not
	if (memcmp(&textColor, &nullColor, sizeof(SDL_Color)) != 0)
	{
		tempColor = *textColor;
	}
	else
		tempColor = defaultColor;

	TTF_Font* tempFont = TTF_OpenFont(tempFontPath, tempFontSize);
	
	if (tempFont != NULL)
	{
		SDL_Surface* tempTextSurface{ TTF_RenderText_Solid(tempFont, textureText, tempColor) };
		freeFont(tempFont);

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
		else
		{
			Output::PrintError("Error loading texture surface", SDL_GetError());
			return nullptr;
		}
	}
	else
	{
		Output::PrintError("Error opening font", SDL_GetError());
		return nullptr;
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
