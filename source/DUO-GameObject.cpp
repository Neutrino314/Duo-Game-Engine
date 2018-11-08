#include "DUO-Scene.h"
#include "DUO-GameObject.h"
#include "DUO-GameObjectComponent.h"
#include "DUO-Utils.h"
#include <SDL2/SDL.h>
#include <vector>

DUO::gameObject::gameObject(int newID, DUO::scene* newScene) : myID(newID), myScene(newScene) {

    componentVector.push_back(new DUO::transform(0, this, 0.0, 0.0, 1.0, 1.0, 0.0));
    curID += 2;

};

void DUO::gameObject::addComponent(DUO::gameObjectComponent* newComponent) {

    if (newComponent->getType() == DUO::componentTypes::RENDERER) {

        componentVector.insert(componentVector.begin() + 1, newComponent);

    } else {

        componentVector.insert(componentVector.begin() + curID, newComponent);
        curID ++;

    }

};

void DUO::gameObject::removeComponent(int componentID) {

    if (componentID >= componentVector.size()) {return;}

    componentVector.erase(componentVector.begin() + componentID - 1);

    curID = componentID;

    for (int i = componentID; i < componentVector.size(); i ++) {

        componentVector[i]->setID(curID);
        curID ++;

    }

};

std::vector<DUO::gameObjectComponent*> DUO::gameObject::getComponents(DUO::componentTypes componentType) {

    std::vector<gameObjectComponent*> resulting;

    for (auto component : componentVector) {

        if (component->getType() == componentType) {

            resulting.push_back(component);

        }

    }

}

void DUO::gameObject::update() {

    for (auto component : componentVector) {

        if (component->getType() != DUO::BASE && component->getType() != DUO::TRANSFORM && component->getType() != DUO::RENDERER) {

            component->update();

        } else {

            continue;

        }

    }

};

void DUO::gameObject::draw(SDL_Renderer* renderer) {

    if (componentVector.size() > 1) {

        componentVector[1]->update();

    }

}



