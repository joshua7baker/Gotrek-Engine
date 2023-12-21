#include <SDL.h>
#include <iostream>
#include "Game.h"

Game* game = nullptr;

enum KeyboardSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

int main(int argv, char* argc[])
{
	game = new Game();
	
	game->init();

	while (game->running())
	{
		game->handleEvents();
		game->render();
	}
	game->clean();

	return 0;
}