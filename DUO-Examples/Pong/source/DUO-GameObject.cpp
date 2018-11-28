#include "DUO-Utils.h"
#include "DUO-GameObjectComponent.h"
#include "DUO-GameObject.h"
#include "DUO-Scene.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <memory>

DUO::gameObject::gameObject(int newID, SDL_Renderer* newRenderer) : myID(newID), myRenderer(newRenderer), myTransform(new DUO::transformComponent(0.0, 0.0, 1.0, 1.0, 0.0, 0, this)) {}

void DUO::gameObject::addComponent(DUO::componentTypes newType, std::shared_ptr<DUO::gameObjectComponent> newComponent) {

    switch (newType) {

    case DUO::RENDERER :

        renderComponentVect.push_back(std::dynamic_pointer_cast<DUO::renderComponent>(newComponent));
        break;

    case DUO::BASE :

        componentVect.push_back(newComponent);
        break;

    default :

        std::cout << "This type is not recognised\n";
        break;

    }

}

void DUO::gameObject::removeComponent(DUO::componentTypes compType, int compID) {

    switch (compType) {

    case DUO::RENDERER :

        renderComponentVect[compID].reset();
        renderComponentVect.erase(renderComponentVect.begin() + compID);
        break;

    case DUO::BASE :

        componentVect[compID].reset();
        componentVect.erase(componentVect.begin() + compID);

        for (int i = compID; i < componentVect.size(); i++) {

            componentVect[i]->setID(i);

        }

        break;

    default :

        std::cout << "This type is not recognised\n";
        break;

    }

}

void DUO::gameObject::setup() {

    for (auto element : componentVect) {

        element->setup();

    }

    for (auto element : renderComponentVect) {

        element->setup();

    }

}

void DUO::gameObject::update() {

    for (auto element : componentVect) {

        element->update();

    }

}

void DUO::gameObject::draw() {

    for (auto element : renderComponentVect) {

        element->update();

    }

}

void DUO::gameObject::move(double newX, double newY) {

    myTransform->translate(newX, newY);

}

SDL_Renderer* DUO::gameObject::getRenderer() {return myRenderer;}

DUO::transformComponent* DUO::gameObject::getTransform() {return myTransform;}

int DUO::gameObject::getCurID(DUO::componentTypes compType) {

    switch (compType) {

    case DUO::BASE :

        return curComponentID;

    case DUO::RENDERER :

        return curRenderID;

    default:

        std::cout << "not recognised\n";
        break;

    }

}