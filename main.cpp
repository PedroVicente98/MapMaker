#include "Canvas.h"
#include "Window.h"
#include <iostream>
#include "SDL.h"


int main(int argc, char* argv[])
{
    Window::Instance()->Init();
    while (Window::Instance()->isRunning())
    {
        Window::Instance()->Events();
        Window::Instance()->Update();
        Window::Instance()->Render();
    }

    Window::Instance()->Clean();

    return 0;
}

/*
int main(int argc, char* argv[]) {

    SDL_Window* window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "D&D",                  // window title
        SDL_WINDOWPOS_CENTERED,              // initial x position
        SDL_WINDOWPOS_CENTERED,             // initial y position
        640,                               // width, in pixels
        480,                              // height, in pixels
        SDL_WINDOW_OPENGL                // flags - see below
    );
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }


    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}
*/