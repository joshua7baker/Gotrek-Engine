#include "Game.h"
#include <iostream>

//Screen Dimension Consts
const int SCREEN_WIDTH{ 640 };
const int SCREEN_HEIGHT{ 480 };

SDL_Texture* testTex = nullptr;
TextureManager* textureManager = nullptr;
Shape* shape;
Viewport* lViewport;
Viewport* rViewport;
Viewport* bViewport;

SDL_Point points[5]{
	{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2},
	{SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 5},
	{SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) - 5},
	{(SCREEN_WIDTH / 2) - 5, SCREEN_HEIGHT / 2},
	{(SCREEN_WIDTH / 2) + 5, SCREEN_HEIGHT / 2}
};

Game::Game() {
}

Game::~Game() {
	IMG_Quit();
}

bool Game::init() {

	bool success{ true };

	//Initialize SDL Library
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		Output::PrintError("SDL could not initialize!", SDL_GetError());
		success = false;
	}
	else
	{
		Output::PrintMessage("SDL Video Library Initialized successfully.");

		//Initialize sdl img for png, this is deinitialized in the Game.cpp deconstructor
		if (SDL_Init(IMG_Init(IMG_INIT_PNG) < 0))
		{
			Output::PrintError("SDL could not initialize!", SDL_GetError());
			success = false;
		}

		//Create window
		gWindow = SDL_CreateWindow("Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			Output::PrintError("Window could not be created!", SDL_GetError());
			success = false;
		}
		//create renderer
		else
		{
			renderer = SDL_CreateRenderer(gWindow, -1, 0);
			if (renderer == NULL)
			{
				Output::PrintError("Renderer could not be created!", SDL_GetError());
				success = false;
			}
			else
			{
				//Set renderer scaling
				SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);

				//fill gScreenSurface white
				SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0xFF, 0xFF, 0xFF));

				//Update window surface
				SDL_UpdateWindowSurface(gWindow);

				Output::PrintMessage("Window & Renderer created successfully.");
			}
		}

		shape = new Shape(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);


		//Test Load
		textureManager = new TextureManager();

		lViewport = new Viewport("LeftVp", 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT /2);
		rViewport = new Viewport("RightVp", SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

		isRunning = true;

		return success;
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type != 0)
	{
		if (event.type == SDL_QUIT)
		{
			isRunning = false;
		}
		else if (event.type == SDL_KEYDOWN)
		#pragma region Input
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				isRunning = false;
				break;

			case SDLK_UP:
				std::cout << "up\n";
				break;

			case SDLK_DOWN:
				std::cout << "down\n";
				break;

			case SDLK_LEFT:
				std::cout << "left\n";
				break;

			case SDLK_RIGHT:
				std::cout << "right\n";
				break;

			default:
				break;
			}
		}
		#pragma endregion
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);

	shape->drawDottedLineShape(renderer, points, sizeof(points));

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(gWindow); ///Destroys allocated surface also (gScreenSurface)
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}

void Game::initError()
{
	std::cout << "error";
}
