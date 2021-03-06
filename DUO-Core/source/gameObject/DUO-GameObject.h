#pragma once

#include "DUO-Utils.h"
#include "DUO-GameObjectComponent.h"
#include <maths/DUO-Vector2.h>
#include <vector>
#include <memory>
#include <map>
#include <SDL2/SDL.h>
#include <typeinfo>
#include <iostream>

namespace DUO {class objectManager;class sceneManager;}

namespace DUO 
{

    class gameObject 
    {

    private:

        std::vector<std::size_t> Layers;

        int myID; //the object's ID
        int nextCompID = 0; //the next id to be assigned to a component
        int nextRenderCompID = 0; //the next ID to be assigned to a render component

        std::vector<std::unique_ptr<DUO::gameObjectComponent>> componentVect; //holds a vector of unique pointers to components
        std::vector<std::unique_ptr<DUO::renderComponent>> renderCompVect; //holds a vector of unique pointers to render components

    public:

        std::unique_ptr<DUO::transformComponent> myTransform; // a unique pointer to a transform component

        DUO::vector2 myVel{0.0, 0.0}; //a vector2 that holds the object's velocity

        gameObject(int newID); //constructor for the class

        ~gameObject() {

            componentVect.clear();
            renderCompVect.clear();
            myTransform.release();
            myTransform.reset();

        };

        void setup(SDL_Renderer* renderer); //this is called by the scene setup method
        void update(); //this is called by the scene supdate method
        void draw(float interpolation, SDL_Renderer* renderer, DUO::vector2 offset); //this is called by the scene draw method

        void setID(int newID); //changes the object's ID
        int getID();

        DUO::vector2 getPos() {return myTransform->pos;}
        DUO::vector2 getVel() {return myVel;}

        friend class DUO::objectManager;
        friend class DUO::sceneManager;
    };
}