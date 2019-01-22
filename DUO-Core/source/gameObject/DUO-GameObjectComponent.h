#pragma once

#include "DUO-Utils.h"
#include <SDL2/SDL.h>
#include <maths/DUO-Vector2.h>
#include <graphics/DUO-Graphics.h>
#include <runtime/DUO-application.h>
#include <memory>
#include <tuple>

namespace DUO {class gameObject;}

namespace DUO 
{

    class gameObjectComponent 
    {

    protected:

        DUO::broadType myBroadType; //stores the comp's broad type
        int myID; //the comp's ID
        const char* myType;

    public:

        gameObjectComponent(int newID); //constructor

        virtual ~gameObjectComponent() {};

        virtual void update() {}; //an update method that all further classes that inherit from this class will override this method

        virtual void setup() {}; //a setup update that will be overriden from deriving classes

        int getID(); //returns the ID of this component

        void setID(int newID); //changes the component's ID

        const char* getType(); //returns the type of this component as a char array obtained using the typeid().name() function

    };

    class transformComponent : public gameObjectComponent 
    {

    public:

        float rotation{0.0}; //a float that holds the rotation in degrees

        DUO::vector2 scale{1.0, 1.0}; //a vector2 that stores the scale attribute of the transform

        DUO::vector2 pos{0.0, 0.0}; //a vector2 that stores the position of the transform

        transformComponent(int newID, float x = 0.0, float y = 0.0, float xScale = 1.0, float yScale = 1.0, float newRot = 0.0); //constructor for the transform

        virtual ~transformComponent() override {delete myType; myType = nullptr;};

        void translate(float x = 0.0, float y = 0.0); //a translation method that translates it a certain amount of units

    };

    class renderComponent : public gameObjectComponent
    {

    protected:

        DUO::transformComponent* myTransform = NULL;

    public:

        DUO::vector2 dimensions{1.0, 1.0}; //the dimensions of the component stored as a vector2

        renderComponent(int newID, float width = 1.0, float height = 1.0, DUO::transformComponent* newTransform = NULL); //constructor

        virtual ~renderComponent() {delete myType; myType = nullptr;};

        virtual void update(DUO::vector2 displayPos, SDL_Renderer* renderer) {}; //overloaded update method taking the position of the object as a parameter

        void setTransform(DUO::transformComponent* transform);

    };

    class polygonRenderer : public renderComponent
    {

    public:

        std::size_t numOfSides{0}; //std::size_t holding the amount of sides that the polygon has

        std::tuple<short, short, short> colour {0, 0, 0};

        bool isFilled{true};

        polygonRenderer(int newID); //constructor

        polygonRenderer(int newID, std::size_t sidesAmount, bool filled,DUO::transformComponent* newTransform = NULL, float width = 1.0, float height = 1.0, short r = 0, short g = 0, short b = 0); //constructor taking in dimensions

        virtual ~polygonRenderer() {delete myType; myType = nullptr;} //deletes the type of the object

        virtual void update(DUO::vector2 displayPos, SDL_Renderer* renderer) override;

    };
   
}