#include "Application.h"


SDL_Texture* texture;

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
		window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
		renderer = SDL_CreateRenderer(window,-1,0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 69, 200, 69, 0.5);
		}
		if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_PNG)))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		}

		canvas = new Canvas(window);
		menu = new Menu(renderer);

		isRunning = true;
	}else
	{
		isRunning = false;
	}


	//texture = IMG_LoadTexture(renderer,"assets/MundoConhecido72.png");
	//std::cout << "Erro Load: " << SDL_GetError() << std::endl;
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
	//SDL_RenderCopy(renderer,texture,NULL,NULL);
	menu->Render();
	canvas->Render();

	std::cout << "Erro textura: " << SDL_GetError() << std::endl;
	SDL_RenderPresent(renderer);
}

void Application::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Application Cleaned" << std::endl;
}

