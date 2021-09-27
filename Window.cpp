#include "Window.h"

Window::Window()
{
   //Initialize non-existant window
   mWindow = NULL;
   mMouseFocus = false;
   mKeyboardFocus = false;
   mFullScreen = false;
   mMinimized = false;
   mWidth = 0;
   mHeight = 0;
}

bool Window::InitWindow(int Width, int Height)
{
    //Create window
    mWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (mWindow != NULL)
    {
        mMouseFocus = true;
        mKeyboardFocus = true;
        mWidth = Width;
        mHeight = Height;


    }
    

    return mWindow != NULL;
}


void Window::test()
{
    SDL_Window* window;                    // Declare a pointer



    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_CENTERED,           // initial x position
        SDL_WINDOWPOS_CENTERED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Check that the window was successfully created
    if (window == NULL) {
    
    }

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    // The window is open: could enter program loop here (see SDL_PollEvent())


    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
}


SDL_Renderer* Window::createRenderer()
{
    return SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Window::handleEvent(SDL_Event& e)
{
    //Window event occured
    if (e.type == SDL_WINDOWEVENT)
    {
        //Caption update flag
        bool updateCaption = false;
        switch (e.window.event)
        {
       
            //Window restored
        case SDL_WINDOWEVENT_RESTORED:
            mMinimized = false;
            break;
        }
    }
}

void Window::free()
{
}

int Window::getWidth()
{
    return mWidth;
}

int Window::getHeight()
{
    return mHeight;
}

bool Window::hasMouseFocus()
{
    return mMouseFocus;
}

bool Window::hasKeyboardFocus()
{
    return mKeyboardFocus;
}

bool Window::isMinimized()
{
    return mMinimized;
}

