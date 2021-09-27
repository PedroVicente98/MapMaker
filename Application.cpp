#include "Application.h"


Application::Application()
{
}

Application::~Application()
{
}


bool Application::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Window window = Window();
	Settings setting = Settings();

	window.InitWindow();
	SDL_Renderer* renderer = window.createRenderer();
	
	while(1)//application loop 
	{
	
	
	
	
	
	}

	return 0;
}



