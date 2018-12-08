#include "DUO-Utils.h"
#include "DUO-GameObjectComponent.h"
#include "DUO-GameObject.h"
#include "DUO-Scene.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <memory>
#include <map>

DUO::gameObject::gameObject(int newID, SDL_Renderer* newRenderer) : myID(newID), myRenderer(newRenderer), myTransform(new DUO::transformComponent(0 ,this ,0.0, 0.0, 1.0, 1.0, 0.0)) {

    static std::map<const char*, int> baseMap;
    static std::map<const char*, int> rendererMap;

    compMap[DUO::BASE] = baseMap;
    compMap[DUO::RENDERER] = rendererMap;

}

void DUO::gameObject::addComponent(DUO::broadType newType, std::shared_ptr<DUO::gameObjectComponent> newComponent) {

    switch (newType) {

    case DUO::RENDERER :

        renderComponentVect.push_back(std::dynamic_pointer_cast<DUO::renderComponent>(newComponent));
        break;

    case DUO::BASE :

        componentVect.push_back(newComponent);
        break;

    default :

        componentVect.push_back(newComponent);
        break;

    }

}

void DUO::gameObject::removeComponent(DUO::broadType compType, int compID) {

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

        componentVect[compID].reset();
        componentVect.erase(componentVect.begin() + compID);

        for (int i = compID; i < componentVect.size(); i++) {

            componentVect[i]->setID(i);

        }
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

    myTransform->translate(myAcceleration.getXComponent(), myAcceleration.getYComponent());

}

void DUO::gameObject::draw(float interpolation) {

    DUO::vector2 displayPos{myAcceleration * interpolation};
    DUO::vector2 oldPos = myTransform->getPosition();

    displayPos = oldPos + displayPos;

    for (auto element : renderComponentVect) {

        element->update(displayPos);

    }

}

void DUO::gameObject::move(double newX, double newY) {

    myTransform->translate(newX, newY);

}

SDL_Renderer* DUO::gameObject::getRenderer() {return myRenderer;}

DUO::transformComponent* DUO::gameObject::getTransform() {return myTransform;}

int DUO::gameObject::getCurID(DUO::broadType compType) {

    switch (compType) {

    case DUO::BASE :

        return curComponentID;

    case DUO::RENDERER :

        return curRenderID;

    default:

        std::cout << "not recognised\n";
        break;

    }

    return DUO::BASE;

}

