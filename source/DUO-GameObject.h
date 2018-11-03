#pragma once

#include "DUO-GameObjectComponent.h"
#include "DUO-Scene.h"
#include <vector>

namespace DUO {

class gameObject {

private:

    std::vector<DUO::component*> componentList;

public:

    short id;

    gameObject(short newID);

    void setup();

    void update();

    void draw();

    void addComponent(DUO::component* newComponent);

    void removeComponent(short componentID);

    friend DUO::component;
    
};

}