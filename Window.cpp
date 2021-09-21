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

bool Window::init()
{
    //Create window
    mWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 5, 5, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (mWindow != NULL)
    {
        mMouseFocus = true;
        mKeyboardFocus = true;
        mWidth = 5;
        mHeight = 5;
    }
    

    return mWindow != NULL;
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
            //Get new dimensions and repaint on window size change
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            mWidth = e.window.data1;
            mHeight = e.window.data2;
            SDL_RenderPresent(gRenderer);
            break;

            //Repaint on exposure
        case SDL_WINDOWEVENT_EXPOSED:
            SDL_RenderPresent(gRenderer);
            break;
            //Mouse entered window
        case SDL_WINDOWEVENT_ENTER:
            mMouseFocus = true;
            updateCaption = true;
            break;

            //Mouse left window
        case SDL_WINDOWEVENT_LEAVE:
            mMouseFocus = false;
            updateCaption = true;
            break;

            //Window has keyboard focus
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            mKeyboardFocus = true;
            updateCaption = true;
            break;

            //Window lost keyboard focus
        case SDL_WINDOWEVENT_FOCUS_LOST:
            mKeyboardFocus = false;
            updateCaption = true;
            break;
            //Window minimized
        case SDL_WINDOWEVENT_MINIMIZED:
            mMinimized = true;
            break;

            //Window maxized
        case SDL_WINDOWEVENT_MAXIMIZED:
            mMinimized = false;
            break;

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

Window::~Window()
{
}
