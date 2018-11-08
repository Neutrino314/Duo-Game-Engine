#pragma once

#include <SDL2/SDL.h>
#include "DUO-Utils.h"
#include "DUO-Maths.h"

namespace DUO {class gameObject;}

namespace DUO {

    class gameObjectComponent {

    protected:

        DUO::componentTypes myType = DUO::componentTypes::BASE;
        int myID;
        DUO::gameObject* myObject;

    public:

        gameObjectComponent(int newID, DUO::gameObject* newObject);

        virtual void setup() {};

        virtual void update() {};

        int getID();

        void setID(int newID);

        DUO::componentTypes getType();

    };

    class transform : public gameObjectComponent {

    private:

        DUO::vector position{0.0, 0.0};
        DUO::vector dimensions{1.0, 1.0};
        double rotation{0.0};

    public:

        transform(int newID, DUO::gameObject* newObject, double x, double y, double width, double height, double newRotation);

        DUO::vector getPosition();
        DUO::vector getDimensions();
        double getRotation();

        void translate(double xInc, double yInc);

        void rotate(double newRot);

    };
    
    class shapeRenderer : public gameObjectComponent {

    protected:

        short r, g, b;
        int width;
        int height;

    public:

        shapeRenderer(int newID, DUO::gameObject* newObject, short newR, short newG, short newB, int newWidth, int newHeight);

        virtual void update(){};

    };

    class polygonRenderer : public shapeRenderer {

        

    };

}