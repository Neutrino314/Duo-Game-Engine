#include "DUO-Utils.h"
#include "DUO-Scene.h"
#include "DUO-GameObject.h"
#include "DUO-GameObjectComponent.h"
#include <vector>
#include <memory>
#include <SDL2/SDL.h>

DUO::scene::scene(int newID, SDL_Renderer* newRenderer) : myID(newID), myRenderer(newRenderer) {

    DUO::scene::addObject(new DUO::gameObject(curID, myRenderer));

}

void DUO::scene::setup() {

    for (auto object : objectVect) {

        object->setup();

    }

}

void DUO::scene::update() {

    for (auto object : objectVect) {

        object->update();

    }

}

void DUO::scene::draw(float interpolation) {

    for (auto object : objectVect) {

        object->draw(interpolation);

    }

}

void DUO::scene::addObject(DUO::gameObject* newObject) {

    objectVect.push_back(newObject);
    curID ++;

}

DUO::gameObject* DUO::scene::getObject(int ID) {return objectVect[ID];}