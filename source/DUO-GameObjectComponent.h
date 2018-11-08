#pragma once

#include <SDL2/SDL.h>
#include "DUO-Utils.h"

namespace DUO {class gameObject;}

namespace DUO {

    class gameObjectComponent {

    private:

        componentTypes myType{DUO::componentTypes::BASE};
        int ID;
        DUO::gameObject* myObject;

    public:

        gameObjectComponent(int newID, DUO::gameObject* newObject);

        virtual void setup();

        virtual void update();

    };

}