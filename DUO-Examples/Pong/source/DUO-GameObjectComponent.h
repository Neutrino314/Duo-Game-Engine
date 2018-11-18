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

        virtual void setup() {};

        virtual void update() {};

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
        void setPosition(double x, double y);

    };

    class renderComponent : public gameObjectComponent {

    protected:

        DUO::vector dimensions{0.0, 0.0};
        transformComponent* myTransform = NULL;

    public:

        renderComponent(int newID, DUO::gameObject* newObject, double width, double height);

        virtual void setup() override {};
        virtual void update() override {};

        DUO::vector getDimensions();
        void setDimensions(double newWidth = 1.0, double newHeight = 1.0);

    };

    class polygonRenderer : public renderComponent {

    private:

        int r, g, b;
        int numberOfSides{3};
        bool isFilled = true;

    public:

        polygonRenderer(int newID, DUO::gameObject* newObject, double width, double height, int newR, int newG, int newB, int sides);

        virtual void update() override;

    };

}