#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
class Window
{
public:
    //Intializes internals
    Window();

    void test();
    //Creates window
    bool InitWindow();

    //Creates renderer from internal window
    SDL_Renderer* createRenderer();

    //Handles window events
    void handleEvent(SDL_Event& e);

    //Deallocates internals
    void free();


    //Window dimensions
    void GetResolution();
    int getWidth();
    int getHeight();

    //Window focii
    bool hasMouseFocus();
    bool hasKeyboardFocus();
    bool isMinimized();

private:
    //Window data
    SDL_Window* mWindow;
    SDL_Renderer* gRenderer;
    //Window dimensions
    int mWidth;
    int mHeight;

    //Window focus
    bool mMouseFocus;
    bool mKeyboardFocus;
    bool mFullScreen;
    bool mMinimized;

};


