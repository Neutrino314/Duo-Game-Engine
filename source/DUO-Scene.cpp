#include "DUO-Scene.h"
#include "DUO-GameObject.h"
#include <SDL2/SDL.h>
#include <vector>

DUO::scene::scene(int newID, SDL_Renderer* newRenderer) : myID(newID), sceneRenderer(newRenderer) {

    objectVect.push_back(new DUO::gameObject(curID, this));
    curID ++;

}

void DUO::scene::update() {

    for (auto object : objectVect) {

        object->update();

    }

}

void DUO::scene::draw() {

    for (auto object : objectVect) {

        object->draw(sceneRenderer);

    }

}

void DUO::scene::addObject(DUO::gameObject* newObject) {

    objectVect.push_back(newObject);
    curID ++;
    
}

void DUO::scene::removeObject(int objectID) {

    

}