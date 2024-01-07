#include "Button.h"
#include "Output.h"
#include "TextureManager.h"

Button::Button(const std::string name, int x, int y, int width, int height, std::string textContent, const char* textureFilePath, SpriteSheet* spriteSheet)
	: buttonName(name), xPos(x), yPos(y), buttonWidth(width), buttonHeight(height)
{
	if (name == "")
	{
		Output::PrintMessage("Button Name could not be assigned, value cannot be empty");
	}

	if (textContent != "")
		buttonText = textContent;

	if (textureFilePath != "")
		t_FilePath = textureFilePath;

	b_Texture = nullptr;

	if (textureFilePath != "" && textureFilePath != nullptr)
	{
		b_Texture = { TextureManager::loadTexture(t_FilePath) };
	}

	if (spriteSheet != nullptr)
		setSpriteSheet(spriteSheet);

	setPosition(x, y);

	destRect = {xPos, yPos, width, height};
	setRenderDest(destRect);
	setButtonStatus(BUTTON_SPRITE_MOUSE_OUT);
	setRenderTexture(b_Texture);
}

Button::~Button(){
}

void Button::setPosition(int x, int y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Button::setButtonStatus(EButtonSprite newStatus)
{
	buttonStatusSprite = newStatus; //Set new button sprite status
	switch (buttonStatusSprite)
	{
		case BUTTON_SPRITE_MOUSE_OUT:
			setSpriteSheetSrcRect((int)BUTTON_SPRITE_MOUSE_OUT);
			break;

		case BUTTON_SPRITE_MOUSE_OVER_MOTION:
			setSpriteSheetSrcRect((int)BUTTON_SPRITE_MOUSE_OVER_MOTION);
			break;

		case BUTTON_SPRITE_MOUSE_DOWN:
			setSpriteSheetSrcRect((int)BUTTON_SPRITE_MOUSE_DOWN);
			break;

		case BUTTON_SPRITE_MOUSE_UP:
			setSpriteSheetSrcRect((int)BUTTON_SPRITE_MOUSE_UP);
			break;

		case BUTTON_SPRITE_TOTAL:
			setSpriteSheetSrcRect((int)BUTTON_SPRITE_TOTAL);
			break;
	}
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


