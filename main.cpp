#include "Application.h"
#include <iostream>
#include "SDL.h"

Application *app = nullptr;

int main(int argc, char* argv[]) {
    app = new Application();
   
    app->Init("Map Maker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600,0);
    while(app->running())
    {
        app->handleEnvents();
        app->update();
        app->render();
    }

    app->clean();

    return 0;
}

