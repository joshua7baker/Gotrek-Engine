#include "Button.h"
#include "Output.h"
#include "TextureManager.h"

Button::Button(std::string& name, int x, int y, int& width, int& height, std::string* textContent,  const char* textureFilePath, SpriteSheet* spriteSheet)
	: buttonName(name), xPos(x), yPos(y), buttonWidth(width), buttonHeight(height), buttonText(*textContent), t_FilePath(textureFilePath)
{
	if (name == "")
	{
		Output::PrintMessage("Button Name could not be assigned, value cannot be empty");
	}
	if (buttonText == "")
	{
		Output::PrintMessage("Button Text could not be assigned, value cannot be empty");
	}

	b_spriteSheet = nullptr; 
	b_Texture = nullptr;

	if (spriteSheet != nullptr)
	{
		b_spriteSheet = spriteSheet;
	}
	else
	{
		if (textureFilePath != "" && textureFilePath != nullptr)
		{
			b_Texture = { TextureManager::loadTexture(t_FilePath) };
		}
	}
	if (b_Texture == nullptr && spriteSheet == nullptr)
		Output::PrintMessage("Error in Button.cpp, one of either b_Texture or spriteSheet must have a value. Cannot both be null");

	m_Position.x = 0;
	m_Position.y = 0;

	setButtonStatus(BUTTON_SPRITE_MOUSE_OUT);
}

Button::~Button()
{
}

void Button::setButtonStatus(EButtonSprite newStatus)
{
	buttonStatusSprite = newStatus;
	switch (buttonStatusSprite)
	{
		case BUTTON_SPRITE_MOUSE_OUT:

			break;

		case BUTTON_SPRITE_MOUSE_OVER_MOTION:
			break;

		case BUTTON_SPRITE_MOUSE_DOWN:
			break;

		case BUTTON_SPRITE_MOUSE_UP:
			break;

		case BUTTON_SPRITE_TOTAL:
			break;

	}
}

void Button::setPosition(int x, int y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Button::handleEvent(SDL_Event* event)
{
	if (event->type == SDL_MOUSEMOTION || event->type == BUTTON_SPRITE_MOUSE_DOWN || event->type == SDL_MOUSEBUTTONUP)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		bool isInside = true;

		//Mouse is left of button
		if (x < m_Position.x)
		{
			isInside = false;
		}
		//Mouse is right of button
		else if (x > m_Position.x + buttonWidth)
		{
			isInside = false;
		}
		//Mouse is above the button
		else if (y < m_Position.y)
		{
			isInside = false;
		}
		//Mouse is below the button
		else if (y > m_Position.y + buttonHeight)
		{
			isInside = false;
		}

		//Mouse is out of sprite
		if (!isInside)
		{
			setButtonStatus(BUTTON_SPRITE_MOUSE_OUT);
		}
		//Mouse is inside sprite
		else
		{
			switch (event->type)
			{
			case SDL_MOUSEMOTION:
				setButtonStatus(BUTTON_SPRITE_MOUSE_OVER_MOTION);
				break;

			case SDL_MOUSEBUTTONDOWN:
				setButtonStatus(BUTTON_SPRITE_MOUSE_DOWN);
				break;

			case SDL_MOUSEBUTTONUP:
				setButtonStatus(BUTTON_SPRITE_MOUSE_UP);
				break;
			}
		}
	}
}

void Button::render()
{
}

