#pragma once
#include <SDL.h>
#include <string>
#include "Structs.h"
#include "RenderableObject.h"
class Button : public RenderableObject
{
public:
	Button(std::string& name, int x, int y, int& width, int& height, std::string* textContent, const char* textureFilePath, SpriteSheet* spriteSheet = nullptr);
	~Button();

	enum EButtonSprite {
		BUTTON_SPRITE_MOUSE_OUT = 0,
		BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
		BUTTON_SPRITE_MOUSE_DOWN = 2,
		BUTTON_SPRITE_MOUSE_UP = 3,
		BUTTON_SPRITE_TOTAL = 4
	};

	void setButtonStatus(EButtonSprite newStatus); //set button enum status
	void setPosition(int x, int y); //set button position
	void handleEvent(SDL_Event* event); //handle mouse event
	void render(); //show button sprite

private:

	std::string buttonName;
	std::string buttonText;
	int xPos;
	int yPos;
	int buttonWidth;
	int buttonHeight;

	const char* t_FilePath = nullptr;
	SDL_Texture* b_Texture;

	SDL_Point m_Position;
	EButtonSprite buttonStatusSprite;
	SpriteSheet* b_spriteSheet;
};

