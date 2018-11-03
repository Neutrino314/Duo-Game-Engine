#pragma once

#include "DUO-GameObject.h"
#include <SDL2/SDL.h>
#include <vector>

namespace DUO {

class scene { //scene class that merely serves as a container for game objects

private:

    std::vector<DUO::gameObject*> objectList;
    int curId{0}; //keeps track of the latest game object ID

public:

    void update();

    void draw();

    void addGameObject();

    void removeGameObject(short objectID);

};

}