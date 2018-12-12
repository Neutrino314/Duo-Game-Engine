#pragma once

#include "DUO-Utils.h"
#include <maths/DUO-Vector2.h>
#include <vector>
#include <memory>
#include <map>
#include <SDL2/SDL.h>
#include <typeinfo>
#include <iostream>

namespace DUO {class scene; class gameObjectComponent; class renderComponent; class transformComponent; class objectManager;}

namespace DUO {

    class gameObject {

    private:

        int myID; //the id of this object
        SDL_Renderer* myRenderer = NULL; //a poiner to an sdl renderer provided by the constructor
        int curRenderID{0}; //the id to be assigned to the next component in the renderComponentVect
        int curComponentID{0}; //the id to be assigned to the next component in the component vector
        DUO::vector2 myAcceleration{0.0, 0.0};

        DUO::transformComponent* myTransform = NULL; //a pointer to a transform component to be instantiated in the constructor

        std::vector<std::shared_ptr<DUO::gameObjectComponent>> componentVect; //a vector of shared_ptrs to basic components
        std::vector<std::shared_ptr<DUO::renderComponent>> renderComponentVect; //a vector of shared_ptrs to renderer components

        std::map<DUO::broadType, std::map<const char*, int>> compMap;
        //This above me is a map of maps which uses a DUO::broadType as a key, the maps it stores consists of ints with compTypes as keys
        //these ints are the indexes of the corresponding components

    public:
    
        gameObject(int newID, SDL_Renderer* newRenderer); 

        void addComponent(DUO::broadType newType, std::shared_ptr<DUO::gameObjectComponent> newComponent);

        void removeComponent(DUO::broadType compType, int compID);

        void setup();

        void update();

        void draw(float interpolation);

        void move(double x, double y);

        int getCurID(DUO::broadType compType);

        DUO::transformComponent* getTransform();

        SDL_Renderer* getRenderer();

        friend class DUO::objectManager;
    };

}