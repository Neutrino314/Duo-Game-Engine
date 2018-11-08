#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <string>
#include "DUO-Scene.h"

#ifndef DUO_RUNTIME
#define DUO_RUNTIME

namespace DUO { //All functions and classes from the engine fall under the namespace DUO
class runtime { //a runtime class that will eventually hold the scene graph, host the game loop and cleanup

private:

    SDL_Window* mainWindow = SDL_CreateWindow("None", 0, 0, 0, 0, SDL_WINDOW_SHOWN); //the main window of the application that is resized in the constructor
    bool isRunning{true}; //the boolean that signifies whether the gameloop is running or not

protected:

    SDL_Event* event = new SDL_Event; //an sdl event variable that wil be used to capture inputs
    int curScene{0};
    std::vector<DUO::scene*> sceneVect;

public:

    SDL_Renderer* mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    static int setupSDL(); //forward declaration of a static function that initialises all SDL modules
    runtime(std::string title, short w, short h); //forward declaration of the constructor taking a title and dimensions for the window
    virtual void setup() = 0; //The setup method that is called before the game loop starts
    void draw(); //the draw method that will be overriden by the user and called after the update
    void update(); //method is overriden by user and callled after event loop
    void gameThread(); //this method runs in a separate thread and incorporates the setup draw and update methods along with the rest of the game loop
    void start(); //this will initialize sdl modules run the game thread and then destroy the SDL modules

};

};

#endif