#include "DUO-Utils.h"
#include <maths/DUO-Vector2.h>
#include "DUO-GameObjectComponent.h"
#include "DUO-GameObject.h"
#include "DUO-Scene.h"
#include <graphics/DUO-Graphics.h>
#include <runtime/DUO-Keyboard.h>
#include <iostream>
#include <memory>

DUO::gameObjectComponent::gameObjectComponent(int newID, DUO::gameObject* newObject) : myID(newID), myObject(newObject)
{

    myBroadType = DUO::BASE; //changes the myBroadType variable to DUO::BASE
    myType = typeid(this).name(); //sets the myType variable

}

int DUO::gameObjectComponent::getID() {return myID;} //returns the comp's ID

void DUO::gameObjectComponent::setID(int ID) {myID = ID;} //sets the comp's ID

const char* DUO::gameObjectComponent::getType() {return myType;} //returns myType

DUO::transformComponent::transformComponent(int newID, DUO::gameObject* newObject, double x, double y, double xScale, double yScale, double newRot) : gameObjectComponent(newID, newObject), rotation(newRot)
{

    myBroadType = DUO::TRANSFORM; //changes the broadType variable to a transform
    myType = typeid(this).name(); //sets the type of the component via the typeid() operator

    pos.setVector(x, y); //sets the position to the new components
    scale.setVector(xScale, yScale); //changes the scale vector to the new components

}

void DUO::transformComponent::translate(double x, double y) {pos.increment(x, y);} //increments the position vector

DUO::renderComponent::renderComponent(int newID, DUO::gameObject* newObject, double width, double height) : gameObjectComponent(newID, newObject)
{

    myBroadType = DUO::RENDERER; //changes the broad type to that of a RENDERER
    myType = typeid(this).name(); //sets the type of the component via the typeid() operator

    dimensions.setVector(width, height); //sets the new dimensions

}