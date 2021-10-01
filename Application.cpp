#include "Application.h"


Application::Application()
{
}

Application::~Application()
{
}


void Application::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	int flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
	if(fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN | flags;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "subsystems Initialised" << std::endl;

		window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
		if(window)
		{
			std::cout << "Window created!!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window,-1,0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer,69,200,69,0.5);
			std::cout << "Renderer created!!" << std::endl;
		}

		isRunning = true;
	}else
	{
		isRunning = false;
	}
}

void Application::handleEnvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;	
	}

}

void Application::update()
{
}

void Application::render()
{
	SDL_RenderClear(renderer);
	//add stuff to render

	SDL_RenderPresent(renderer);
}

void Application::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Application Cleaned" << std::endl;
}

//void Application::GetDisplayMode()
//{
//	SDL_GetCurrentDisplayMode(0, DM);
//	Width = DM->w;
//	Height = DM->h;	
//}


/*SDL_Init(SDL_INIT_EVERYTHING);
	\
	Settings setting = Settings();

	
	SDL_Renderer* renderer = window.createRenderer();
	
	bool running = true;
	SDL_Event event;

	while(running)//application loop 
	{

		while (SDL_PollEvent(&event)) 
		{  
			if (event.type == SDL_QUIT)
			{
				running = false; 
				break;
			}
				


		}	
	}

	return 0;*/