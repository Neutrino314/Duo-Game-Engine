#pragma once

#include "DUO-Utils.h"
#include <SDL2/SDL.h>
#include <maths/DUO-Vector2.h>
#include <graphics/DUO-Graphics.h>
#include <memory>

namespace DUO {class gameObject;}

namespace DUO {

    class gameObjectComponent {

    protected:

        int myID;
        DUO::broadType myType{DUO::BASE};
        DUO::gameObject* myObject;

    public:

        gameObjectComponent(int newID, DUO::gameObject* newObject);

        int getID();

        void setID(int newID);

        DUO::broadType getType();

        virtual void setup() {};

        virtual void update() {};

    };

    class transformComponent : public gameObjectComponent {

    private:

        DUO::vector2 position{0.0, 0.0};
        DUO::vector2 scale{1.0, 1.0};
        double rotation{0.0};

    public:

        transformComponent(double newX, double newY, double newXScale, double newYScale, double newRotation, int newID, DUO::gameObject* newGameObject);

        DUO::vector2 getPosition();
        DUO::vector2 getScale();
        double getRotation();

        bool translate(double xInc, double yInc);
        bool rotate(double rotInc);
        bool rescale(double xScale, double yScale);
        void setPosition(double x, double y);

    };

    class renderComponent : public gameObjectComponent {

    protected:

        DUO::vector2 dimensions{0.0, 0.0};
        transformComponent* myTransform = NULL;

    public:

        renderComponent(int newID, DUO::gameObject* newObject, double width, double height);

        virtual void setup() override {};
        virtual void update(DUO::vector2 objectPos){};

        DUO::vector2 getDimensions();
        void setDimensions(double newWidth = 1.0, double newHeight = 1.0);

    };

    class polygonRenderer : public renderComponent {

    private:

        int r, g, b;
        int numberOfSides{3};
        bool isFilled = true;

    public:

        polygonRenderer(int newID, DUO::gameObject* newObject, double width, double height, int newR, int newG, int newB, int sides);

        virtual void update(DUO::vector2 objectPos) override;

    };

    class spriteRenderer : public renderComponent {

    private:

        SDL_Texture* myTexture = NULL;

    public:

        spriteRenderer(std::string path, int newID, DUO::gameObject* newObject, double width = 1.0, double height = 1.0);

        virtual void update(DUO::vector2 objectPos) override;

    };

}