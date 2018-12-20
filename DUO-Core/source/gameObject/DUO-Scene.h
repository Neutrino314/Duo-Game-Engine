#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "DUO-Utils.h"
#include "DUO-Scene.h"

namespace DUO {class gameObject; class gameObjectComponent; class sceneManager;}

namespace DUO 
{

    class scene 
    {

    private:

        SDL_Renderer* myRenderer = NULL; //pointer to an SDL_Renderer provided by the application class
        int myID; //an integer holding the object's ID which can be used to find it in a scene vector

        int nextObjectID = 0; //the next ID to be assigned to a game object in the vector

        std::vector<std::unique_ptr<DUO::gameObject>> objectVect; //a std::vector of unique pointers to game objects

    public:

        scene(int newID, SDL_Renderer* renderer); //constructor for the scene object taking a new ID and a pointer to a Renderer object

        void setup(); //a method that is when the scene is loaded

        void update(); //this is called by the application::update() method and updates each object in the object vector
        
        void draw(float interpolation); //renders the objects in the object vector and supplies interpolation to the objects

        friend class DUO::sceneManager; //friend class that will provide an interface for this class

    };

}