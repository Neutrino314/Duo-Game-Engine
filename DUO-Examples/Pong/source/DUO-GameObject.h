#pragma once

#include "DUO-Utils.h"
#include <vector>
#include <memory>
#include <SDL2/SDL.h>

namespace DUO {class scene; class gameObjectComponent; class renderComponent; class transformComponent;}

namespace DUO {

    class gameObject {

    private:

        int myID; //the id of this object
        SDL_Renderer* myRenderer = NULL; //a poiner to an sdl renderer provided by the constructor
        int curRenderID{0}; //the id to be assigned to the next component in the renderComponentVect
        int curPhysicsID{0}; // the id to be assigned to the next component in the physicsComponentVect
        int curComponentID{0}; //the id to be assigned to the next component in the component vector

        DUO::transformComponent* myTransform = NULL; //a pointer to a transform component to be instantiated in the constructor

        std::vector<std::shared_ptr<DUO::gameObjectComponent>> componentVect; //a vector of shared_ptrs to basic components
        std::vector<std::shared_ptr<DUO::renderComponent>> renderComponentVect; //a vector of shared_ptrs to renderer components

    public:

        gameObject(int newID, SDL_Renderer* newRenderer); 

        void addComponent(DUO::componentTypes newType, std::shared_ptr<DUO::gameObjectComponent> newComponent);

        void removeComponent(DUO::componentTypes compType, int compID);

        void setup();

        void update();

        void draw();

        void move(double x, double y);

        int getCurID(DUO::componentTypes compType);

        DUO::transformComponent* getTransform();

        SDL_Renderer* getRenderer();

    };

}