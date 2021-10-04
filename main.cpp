#include "Application.h"
#include <iostream>
#include "SDL.h"

Application *app = nullptr;

int main(int argc, char* argv[]) {
    
    const int FPS = 60;//change to Settings Variable
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;
    
    app = new Application();
    app->Init("Map Maker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600,0);
   
    while(app->running())
    {
        frameStart = SDL_GetTicks();

        app->handleEnvents();
        app->update();
        app->render();
       
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay-frameTime);
        }

    }

    app->clean();

    return 0;
}

