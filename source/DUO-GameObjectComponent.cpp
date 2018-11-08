#include "DUO-GameObjectComponent.h"
#include "DUO-GameObject.h"
#include "DUO-Utils.h"
#include "DUO-Graphics.h"
#include <vector>

DUO::gameObjectComponent::gameObjectComponent(int newID, DUO::gameObject* newObject) : myID(newID), myObject(newObject) {}

void DUO::gameObjectComponent::setID(int newID) {myID = newID;}

int DUO::gameObjectComponent::getID() {return myID;};

DUO::componentTypes DUO::gameObjectComponent::getType() {return myType;}

DUO::transform::transform(int newID, DUO::gameObject* newObject, double x, double y, double width, double height, double newRotation) : 
    gameObjectComponent(newID, newObject), rotation(newRotation) {

        position.setVector(x, y);
        dimensions.setVector(width, height);
        myType = DUO::TRANSFORM;

}

void DUO::transform::translate(double xInc, double yInc) {position.increment(xInc, yInc);};

void DUO::transform::rotate(double newRotation) {rotation += newRotation;};

double DUO::transform::getRotation() {return rotation;};

DUO::vector DUO::transform::getPosition() {return position;};

DUO::vector DUO::transform::getDimensions() {return dimensions;};

DUO::shapeRenderer::shapeRenderer(int newID, DUO::gameObject* newObject, short newR, short newG, short newB, int newWidth, int newHeight)

: gameObjectComponent(newID, newObject), r(newR), g(newG), b(newB), width(newWidth), height(newHeight) {

    myType = DUO::RENDERER;

}

