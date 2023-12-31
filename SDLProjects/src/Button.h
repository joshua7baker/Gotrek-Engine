#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include "Structs.h"
#include "RenderableObject.h"
class Button : public RenderableObject
{
public:
	Button(const std::string name, int x, int y, int width, int height, std::string textContent = "", const char* textureFilePath = nullptr, SpriteSheet* spriteSheet = nullptr);
	~Button();

	enum EButtonSprite {
		BUTTON_SPRITE_MOUSE_OUT = 0,
		BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
		BUTTON_SPRITE_MOUSE_DOWN = 2,
		BUTTON_SPRITE_MOUSE_UP = 3,
		BUTTON_SPRITE_TOTAL = 4
	};

	void setPosition(int x, int y); //set button position
	void setButtonStatus(EButtonSprite newStatus); //set button enum status
	void handleEvent(SDL_Event* event); //handle mouse event

private:

	std::string buttonName;
	int xPos;
	int yPos;
	int buttonWidth;
	int buttonHeight;
	std::string buttonText;

	const char* t_FilePath = nullptr;
	SDL_Texture* b_Texture;

	SDL_Point m_Position;
	EButtonSprite buttonStatusSprite;

	SDL_Rect destRect;
}; 

