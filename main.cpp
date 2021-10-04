#include "Application.h"
#include <iostream>
#include "SDL.h"

Application *app = nullptr;

int main(int argc, char* argv[]) {
    app = new Application();
    int cont = 0;
    app->Init("Map Maker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600,0);
    while(app->running())
    {
        app->handleEnvents();
        app->update();
        app->render();
       std::cout<< cont++ <<std::endl;
    }

    app->clean();

    return 0;
}

