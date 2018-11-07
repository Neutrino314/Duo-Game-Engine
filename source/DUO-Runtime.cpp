#include <string>
#include <SDL2/SDL.h>
#include <iostream>
#include "DUO-Runtime.h"
#include "DUO-Graphics.h"
#include <thread>

DUO::runtime::runtime(std::string title, short w, short h) { //constructor taking a title, width and height as parameters

    SDL_SetWindowSize(mainWindow, w, h); //resizing the window using SDL_SetWindowSize
    SDL_SetWindowTitle(mainWindow, title.c_str()); //re-titling the window using the SDL_SetWindowTitle function
};

void DUO::runtime::update() {


}

void DUO::runtime::draw() {

    DUO::drawPolygon(20, 50, 400, 400, 255, 255, 255, mainRenderer, 0.0);

}

void DUO::runtime::gameThread() {

    while (isRunning) { //while loop that runs while isRunning is true

        while (SDL_PollEvent(event)) { //updates the event queue

            if (event->type == SDL_QUIT) { //if the window is closed then call SDL_QUIT and set isRunning to false

                isRunning = false; 

            }

        }

        update(); //calls the update function

        SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 0); //sets the renderer's drawing colour to black

        SDL_RenderClear(mainRenderer); //clears the renderer

        draw(); // calls the draw function

        SDL_RenderPresent(mainRenderer); //presents the changes to the renderer

    }

};

void DUO::runtime::start() {

    setup(); //calls the setup function

    std::thread gameLoop(&DUO::runtime::gameThread, this); //creates a thread running the gameThread function
    gameLoop.join(); //joins the thread

    delete event; //once the thread has ended delete the event variable and set the pointer's address to nullptr
    event = nullptr;

    SDL_DestroyWindow(mainWindow); //destroys the window and sets the pointer's address to nullptr
    mainWindow = nullptr;

    SDL_DestroyRenderer(mainRenderer); //destroys the renderer and sets the pointer's address to nullptr
    mainRenderer = nullptr;

};

int DUO::runtime::setupSDL() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0){ //initialises SDL video however if there is an error it exits the function and prints the error returning 1 otherwise it returns 0
	
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	
    return 1;
    
    }

    return 0;

};