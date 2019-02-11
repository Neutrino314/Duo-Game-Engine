#include <gameObject/DUO-GameObject.h>
#include <gameObject/DUO-GameObjectComponent.h>
#include <gameObject/DUO-Scene.h>

#include <maths/DUO-Vector2.h>
#include "camera.h"

DUO::camera::camera(bool targeted) : hasTarget(targeted)
{
}

DUO::camera::~camera()
{
}

int DUO::camera::getTargetID() {

    if (!hasTarget)
        return 0;

    return targetID;

}

void DUO::camera::setTargetID(int ID)
{

    if (!hasTarget)
        return;
    else
        targetID = ID;  

}

void DUO::camera::loadTarget(DUO::gameObject* go)
{

    if (!hasTarget)
        return;
    else
        myObj = go;

}

void DUO::camera::setup()
{

    if (!hasTarget)
        return;

    origin = myObj->getPos();

    pos = origin;

}

void DUO::camera::update()
{

    if (!hasTarget)
        return;

    pos = myObj->getPos();

}

void DUO::camera::calculateOffset(float interpolation)
{

    DUO::vector2 tempVel = myObj->myVel;

    DUO::vector2 dispPos{tempVel * interpolation};

    dispPos = dispPos + pos;

    offset = origin - dispPos;

}