#include "DUO-Scene.h"
#include "DUO-GameObject.h"

void DUO::scene::addObject() {

    objectVect.push_back(new DUO::gameObject(curID));
    curID ++;

};

void DUO::scene::removeObject(int objectID) {

    objectVect.erase(objectVect.begin() + curID);
            for (int i = objectID; i < objectVect.size(); i ++) {

                objectVect[i]->setID(i);

            }

            curID --;

};