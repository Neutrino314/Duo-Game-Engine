#pragma once

#include "DUO-Utils.h"
#include <SDL2/SDL.h>
#include <maths/DUO-Vector2.h>
#include <graphics/DUO-Graphics.h>
#include <runtime/DUO-application.h>
#include <memory>

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

        double rotation{0.0}; //a double that holds the rotation in degrees

        DUO::vector2 scale{1.0, 1.0}; //a vector2 that stores the scale attribute of the transform

        DUO::vector2 pos{0.0, 0.0}; //a vector2 that stores the position of the transform

        transformComponent(int newID, double x = 0.0, double y = 0.0, double xScale = 1.0, double yScale = 1.0, double newRot = 0.0); //constructor for the transform

        virtual ~transformComponent() {};

        void translate(double x = 0.0, double y = 0.0); //a translation method that translates it a certain amount of units

    };

    class renderComponent : public gameObjectComponent
    {

    public:

        DUO::vector2 dimensions{1.0, 1.0}; //the dimensions of the component stored as a vector2

        renderComponent(int newID, double width = 1.0, double height = 1.0); //constructor

        virtual ~renderComponent() {};

        virtual void update(DUO::vector2 displayPos, SDL_Renderer* renderer) {}; //overloaded update method taking the position of the object as a parameter

    };
   
}