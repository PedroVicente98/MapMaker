#include "Window.h"

Window::Window()
{
   //Initialize non-existant window
   mWindow = NULL;
   mMouseFocus = false;
   mKeyboardFocus = false;
   mFullScreen = false;
   mMinimized = false;
   GetResolution();
}

void Window::GetResolution()
{
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    mWidth = DM.w;
    mHeight = DM.h;
}

bool Window::InitWindow()
{
    //Create window
    mWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mWidth, mHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (mWindow != NULL)
    {
        mMouseFocus = true;
        mKeyboardFocus = true;
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
        std::cout << "Failed to initialise SDL Window for PNG files: " << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cout << "Failed to initialise SDL_image for PNG files: " << IMG_GetError() << std::endl;
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

