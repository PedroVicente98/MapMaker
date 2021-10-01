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
	
	
	std::cout << "console mostra";
	while(1)//application loop 
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) {  // poll until all events are handled!
			/*switch (event)
			{
			default:
				break;
			}*/


		// decide what to do with this event.
		}
	
	
	
	
	}

	return 0;
}



