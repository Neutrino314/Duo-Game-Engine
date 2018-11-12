#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "DUO-Utils.h"

namespace DUO {class gameObject; class gameObjectComponent;}

namespace DUO{

    class scene {

    private:

        int myID; //the ID of this scene object to be used by the runtime instance to address which scene to update
        int curID{0}; //the current ID to be assigned to the next object in the game object vector
        SDL_Renderer* myRenderer; //a pointer to an SDL renderer object provided by the runtime object
        std::vector<std::shared_ptr<DUO::gameObject>> objectVect; //a vector of shared pointers to gameObjects

    public:

        scene(int newID, SDL_Renderer* newRenderer); //constructor for the scene class taking an ID and a renderer object

        void setup(); //a setup function that is called before the first update method

        void update(); //an update method that returns a boolean value

        void draw(); //a draw method that returns a boolean value dependant on the success of the update

        void addObject(std::shared_ptr<DUO::gameObject> newObject); //adds a new gameObject instance to the object vector

        void removeObject(int objectID); //removes a gameObject from the object vector with a specified ID 

        void addObjectComponent(DUO::gameObjectComponent* newComponent, DUO::componentTypes newCompType, int objectID); //adds a new component to the object with the specified ID

        std::shared_ptr<DUO::gameObject> getObject(int ID);

    };

}