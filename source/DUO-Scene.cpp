#include "DUO-Scene.h"
#include "DUO-GameObject.h"

void DUO::scene::update() {

    for (auto* object : objectList) {

        object->update();

    }

};

void DUO::scene::draw() {

    for (auto* object : objectList) {

        object->draw();

    }

};

void DUO::scene::addGameObject() {

    objectList.push_back(new DUO::gameObject(curId));
    curId ++;

};

void DUO::scene::removeGameObject(short objectID) {

    

}