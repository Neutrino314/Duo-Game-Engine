#include <SDL2/SDL.h>
#include <iostream>
#include "DUO-Scene.h"
#include <vector>
#include <string>

#ifndef DUO_application
#define DUO_application

namespace DUO { //All functions and classes from the engine fall under the namespace DUO

    class application { //a application class that will eventually hold the scene graph, host the game loop and cleanup

    private:

        SDL_Window* mainWindow = SDL_CreateWindow("None", 0, 0, 0, 0, SDL_WINDOW_SHOWN); //the main window of the application that is resized in the constructor
        bool isRunning{true}; //the boolean that signifies whether the gameloop is running or not
        const int TICKS_PER_SECOND{30};
        const int SKIP_TICKS{1000 / TICKS_PER_SECOND};
        const int MAX_SKIP{5};
        Uint32 nextGameTick = SDL_GetTicks();
        int loops;
        float interpolation{0.0f};
        int curFrame{0};

    protected:

        SDL_Event* event = new SDL_Event; //an sdl event variable that wil be used to capture inputs
        static int curScene;

    public:

        static std::vector<scene*> sceneVect;
        SDL_Renderer* mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        static int setupSDL(); //forward declaration of a static function that initialises all SDL modules
        application(std::string title, short w, short h); //forward declaration of the constructor taking a title and dimensions for the window
        virtual void setup() = 0; //The setup method that is called before the game loop starts
        virtual void draw(float newInterpolation); //the draw method that will be overriden by the user and called after the update
        virtual void update(); //method is overriden by user and callled after event loop
        void gameThread(); //this method runs in a separate thread and incorporates the setup draw and update methods along with the rest of the game loop
        void start(); //this will initialize sdl modules run the game thread and then destroy the SDL modules
        static void changeScene(int newScene); //changes the scene to the one specified

    };

};

#endif