#include "Game.h"
#include "GameObject.h"
#include "TextObject.h"
#include "Button.h"

//Screen Dimension Consts, setup a settings class later on to hold all game settings
/*const int screenWidth{ 640 };
const int screenHeight{ 480 }; */ 

TextObject* testText = nullptr;
TextObject* testText2;
TextObject* testText3;
SpriteSheet* testbuttonsheet;
Button* testBtn;

Game::Game() {
	gameSettings = new GameSettings();
}

Game::~Game() {
}

bool Game::init() {

	//Initialize game settings as these are mandatory to load SDL_Sub-systems
	gameSettings->setGameResolution(640, 480);

	screenWidth = *gameSettings->getScreenWidth();
	screenHeight = *gameSettings->getScreenHeight();

	bool success{ true };

	//Initialize SDL Library
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		Output::PrintError("SDL could not initialize!", SDL_GetError());
		success = false;

		return false;
	}
	else
	{
		Output::PrintMessage("SDL Video Library Initialized successfully.");

		//Initialize SDL IMG
		if (SDL_Init(IMG_Init(IMG_INIT_PNG) < 0))
		{
			Output::PrintError("SDL could not initialize!", SDL_GetError());
			success = false;
		}

		//Initialize SDL TTF
		if (SDL_Init(TTF_Init() == -1))
		{
			Output::PrintError("SDL ttf could not be initialized!", SDL_GetError());
			success = false;
		}

		//Create Window
		gWindow = SDL_CreateWindow("Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			Output::PrintError("Window could not be created!", SDL_GetError());
			success = false;
		}
		//Create Renderer
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
				SDL_RenderSetLogicalSize(renderer, screenWidth, screenHeight);

				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);

				//fill gScreenSurface white
				SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0xFF, 0xFF, 0xFF));

				//Update window surface
				SDL_UpdateWindowSurface(gWindow);

				Output::PrintMessage("Window & Renderer created successfully.");
			}
		}

		//Initialize Texture Manager Variables
		if (TextureManager::setRenderer(renderer))
		{
			Output::PrintMessage("TextureManager.cpp default renderer set successfully.");
		}
		else
			Output::PrintMessage("TextureManager.cpp default renderer setup failed.");

		if (TextureManager::setDefaultFont("assets/fonts/Freedom-10eM.ttf", 32, { 0xFF,0xFF,0xFF,0xFF }))
		{
			Output::PrintMessage("Default font setup successfully.");
		}
		else 
			Output::PrintMessage("Default font setup failed.");

		//testText = new TextObject("Test Thing", "Test Text Here", screenWidth / 2, screenHeight / 5);
		//testText2 = new TextObject("Test Thing", "TIm here too!", screenWidth / 2, screenHeight / 3, nullptr);
		//testText3 = new TextObject("Test Thing", "Weenie!", screenWidth / 2, screenHeight / 2, nullptr);

		GameObject* gameObjOne = new GameObject("Test", screenWidth / 2, screenHeight / 2, "assets/foo.png", nullptr);


		renderManager = new RenderManager(renderer);
		renderManager->addObject(gameObjOne);

		testbuttonsheet = new SpriteSheet("button test");
		testBtn = new Button("Test Button", screenWidth / 2, screenHeight / 2, 200, 100, "", "assets/buttontest.png", testbuttonsheet);

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
		
		//Handle button events (Utilize a vector to hold all button & their events in the future)
		//testBtn->handleEvent(&event);

		if (event.type == SDL_KEYDOWN)
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

//Render imagery to screen
void Game::render()
{
	SDL_RenderClear(renderer);
	//renderManager->renderButtonObject(testBtn);
	renderManager->renderObjects();
	SDL_RenderPresent(renderer);
}


//Clean and deallocate resources, then quit the application
void Game::clean()
{
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	gWindow = NULL;
	
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}

void Game::initError()
{
	std::cout << "error";
}
