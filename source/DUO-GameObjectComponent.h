#pragma once

#include "DUO-Utils.h"
#include <SDL2/SDL.h>
#include "DUO-Maths.h"

namespace DUO {class gameObject;}

namespace DUO {

    class gameObjectComponent {

    protected:

        int myID;
        DUO::componentTypes myType{DUO::BASE};
        DUO::gameObject* myObject = NULL;

    public:

        gameObjectComponent(int newID, DUO::gameObject* newObject);

        int getID();

        void setID(int newID);

        DUO::componentTypes getType();

        virtual bool setup() {};

        virtual bool update() {};

    };

    class transformComponent : public gameObjectComponent {

    private:

        DUO::vector position{0.0, 0.0};
        DUO::vector scale{1.0, 1.0};
        double rotation{0.0};

    public:

        transformComponent(double newX, double newY, double newXScale, double newYScale, double newRotation, int newID, DUO::gameObject* newGameObject);

        DUO::vector getPosition();
        DUO::vector getScale();
        double getRotation();

        bool translate(double xInc, double yInc);
        bool rotate(double rotInc);
        bool rescale(double xScale, double yScale);

    };

}