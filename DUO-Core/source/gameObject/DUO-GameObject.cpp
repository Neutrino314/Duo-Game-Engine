#include "DUO-Utils.h"
#include "DUO-GameObjectComponent.h"
#include "DUO-GameObject.h"
#include "DUO-Scene.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <memory>
#include <map>

DUO::gameObject::gameObject(int newID, SDL_Renderer* renderer) : myRenderer(renderer), myID(newID)
{

    myTransform = std::unique_ptr<DUO::transformComponent>(new DUO::transformComponent(0, this));
    //adding a new transform to the object with default values and a pointer to the object

}

void DUO::gameObject::setup() 
{

    for (const auto& comp : componentVect)
    {

        comp->setup();

    }

}

void DUO::gameObject::update()
{

    for (const auto& comp : componentVect)
    {

        comp->update();

    }

    myTransform->translate(myVel.getXComponent(), myVel.getYComponent());

}

void DUO::gameObject::draw(float interpolation)
{

    DUO::vector2 displayPos{myVel * static_cast<double>(interpolation)};
    DUO::vector2 oldPos{myTransform->pos};

    displayPos = oldPos + displayPos;

    for (const auto& comp : renderCompVect)
    {

        comp->update(displayPos);

    }

}