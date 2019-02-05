#include "DUO-Utils.h"
#include "DUO-GameObjectComponent.h"
#include "DUO-GameObject.h"
#include "DUO-Scene.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <memory>
#include <map>

DUO::gameObject::gameObject(int newID) : myID(newID)
{

    myTransform = std::unique_ptr<DUO::transformComponent>(new DUO::transformComponent(0));
    //adding a new transform to the object with default values and a pointer to the object

}

void DUO::gameObject::setup(SDL_Renderer* renderer) 
{

    for (const auto& comp : componentVect)
    {

        if (comp != nullptr)
        {
            comp->setup();
        }

    }

    for (const auto& comp : renderCompVect)
    {

        if (comp != nullptr)
        {

            comp->setup(renderer);

        }

    }

}

void DUO::gameObject::update()
{

    for (const auto& comp : componentVect)
    {
        
        if (comp != nullptr)
        {
        comp->update();
        }

    }

    myTransform->translate(myVel.x, myVel.y);

}

void DUO::gameObject::draw(float interpolation, SDL_Renderer* renderer)
{

    DUO::vector2 displayPos{myVel * interpolation};
    DUO::vector2 oldPos{myTransform->pos};

    displayPos = oldPos + displayPos;

    for (const auto& comp : renderCompVect)
    {

        if (comp != nullptr)
        {
        comp->update(myTransform->pos, renderer);
        }
        
    }

}

void DUO::gameObject::setID(int newID) {myID = newID;}

int DUO::gameObject::getID() {return myID;}