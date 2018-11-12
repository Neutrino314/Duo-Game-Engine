#include "DUO-Utils.h"
#include "DUO-GameObjectComponent.h"
#include "DUO-GameObject.h"
#include "DUO-Scene.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <memory>

DUO::gameObject::gameObject(int newID, SDL_Renderer* newRenderer) : myID(newID), myRenderer(newRenderer), myTransform(new DUO::transformComponent(0.0, 0.0, 1.0, 1.0, 0.0, 0, this)) {}

template <typename T>

void DUO::gameObject::addComponent(DUO::componentTypes newType, T* newComponent) {

    switch (newType) {

    case DUO::RENDERER :

        std::cout << "not yet implemented\n";
        return true;

    case DUO::BASE :

        componentVect.push_back(std::make_shared<gameObjectComponent>(newComponent));
        return true;

    case default:

        std::cout << "This type is not recognised\n";
        return false;

    }

}

void DUO::gameObject::removeComponent(DUO::componentTypes compType, int compID) {

    switch (compType) {

    case DUO::RENDERER :

        renderComponentVect[compID].reset();
        renderComponentVect.erase(renderComponentVect.begin() + compID);

    }

}