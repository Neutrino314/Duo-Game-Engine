#include <string>
#include <SDL2/SDL.h>
#include <iostream>
#include "DUO-Runtime.h"
#include <thread>

DUO::runtime::runtime(std::string title, short w, short h) { //constructor taking a title, width and height as parameters

    SDL_SetWindowSize(mainWindow, w, h); //resizing the window using SDL_SetWindowSize
    SDL_SetWindowTitle(mainWindow, title.c_str()); //re-titling the window using the SDL_SetWindowTitle function

};

void DUO::runtime::gameThread() {

    while (isRunning) {

        while (SDL_PollEvent(event)) {

            if (event->type == SDL_QUIT) {

                isRunning = false;

            }

        }

        update();

        SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 0);

        SDL_RenderClear(mainRenderer); 

        draw();

        SDL_RenderPresent(mainRenderer);

    }

};

void DUO::runtime::start() {

    setup();

    std::thread gameLoop(&DUO::runtime::gameThread, this);
    gameLoop.join();

    delete event;
    event = nullptr;

    SDL_DestroyWindow(mainWindow);
    mainWindow = nullptr;

    SDL_DestroyRenderer(mainRenderer);
    mainRenderer = nullptr;

};

int DUO::runtime::setupSDL() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0){
	
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	
    return 1;
    
    }

    return 0;

};