#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "DUO-application.h"
#include "DUO-Keyboard.h"
#include <graphics/DUO-Graphics.h>
#include <gameObject/DUO-Scene.h>
#include <maths/DUO-Vector2.h>
#include <thread>
#include <vector>

int DUO::application::curScene = 0;
SDL_Event* DUO::application::event = new SDL_Event;
std::vector<DUO::scene*> DUO::application::sceneVect;

DUO::application::application(std::string title, short w, short h) { //constructor taking a title, width and height as parameters

    SDL_SetWindowSize(mainWindow, w, h); //resizing the window using SDL_SetWindowSize
    SDL_SetWindowTitle(mainWindow, title.c_str()); //re-titling the window using the SDL_SetWindowTitle function

    DUO::application::sceneVect.push_back(new DUO::scene(0, mainRenderer)); // adds a new scene to the scene vector 

};

void DUO::application::update() {

    DUO::application::sceneVect[DUO::application::curScene]->update(); //calls the current scene's update method
    
    if (curFrame == TICKS_PER_SECOND) {

        curFrame = 1; 

    } else {

        curFrame ++;

    }

}

void DUO::application::draw(float newInterpolation) {

    DUO::application::sceneVect[DUO::application::curScene]->draw(interpolation); //calls the current scene's draw method
    

}

void DUO::application::gameThread() {

    while (isRunning) { //while loop that runs while isRunning is true

        loops = 0;

        while (SDL_PollEvent(event)) { //updates the event queue

            if (event->type == SDL_QUIT) { //if the window is closed then call SDL_QUIT and set isRunning to false

                isRunning = false; 

            }

        }

        while (SDL_GetTicks() > nextGameTick && loops < MAX_SKIP) {

            update(); //calls the update function

            nextGameTick += SKIP_TICKS;
            loops ++;

        }

        interpolation = static_cast<float>((SDL_GetTicks() + SKIP_TICKS) - (nextGameTick / SKIP_TICKS));

        SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 0); //sets the renderer's drawing colour to black

        SDL_RenderClear(mainRenderer); //clears the renderer

        //std::cout << "drawn\n";

        draw(interpolation); // calls the draw function

        SDL_RenderPresent(mainRenderer); //presents the changes to the renderer

        DUO::keyboard::update();

    }

};

void DUO::application::setup() {

    sceneVect[curScene]->setup();

}

void DUO::application::start() {

    setup(); //calls the setup function

    std::thread gameLoop(&DUO::application::gameThread, this); //creates a thread running the gameThread function
    gameLoop.join(); //joins the thread

    delete event; //once the thread has ended delete the event variable and set the pointer's address to nullptr
    event = nullptr;

    SDL_DestroyWindow(mainWindow); //destroys the window and sets the pointer's address to nullptr
    mainWindow = nullptr;

    SDL_DestroyRenderer(mainRenderer); //destroys the renderer and sets the pointer's address to nullptr
    mainRenderer = nullptr;

};

int DUO::application::setupSDL() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0){ //initialises SDL video however if there is an error it exits the function and prints the error returning 1 otherwise it returns 0
	
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	
        return 1;
    
    }

    int imgFlags = IMG_INIT_PNG;

    if( !( IMG_Init( imgFlags ) & imgFlags ) ) {

        std::cout << "SDL_Init Error: " << IMG_GetError() << std::endl;
        return 2;

    }

    return 0;

};

void DUO::application::changeScene(int newScene) {

    if (newScene > static_cast<int>(DUO::application::sceneVect.size())) {

        std::cout << "new scene index excedes the size of the scenevect\n";
        return;

    } else {

        DUO::application::curScene = newScene;
        return;

    }

}

DUO::vector2 DUO::application::getMousePos() {

    int x, y;

    SDL_GetMouseState(&x, &y);

    return DUO::vector2(static_cast<double>(x), static_cast<double>(y));

}

SDL_Event* DUO::application::getEvent() {return event;}