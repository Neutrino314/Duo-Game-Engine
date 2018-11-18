#include "DUO-Utils.h"
#include "DUO-Maths.h"
#include "DUO-GameObjectComponent.h"
#include "DUO-GameObject.h"
#include "DUO-Scene.h"
#include "DUO-Graphics.h"
#include "DUO-Keyboard.h"
#include <iostream>

DUO::gameObjectComponent::gameObjectComponent(int newID, DUO::gameObject* newObject) : myObject(newObject), myType(DUO::BASE) {

    myID = myObject->getCurID(myType);

};

int DUO::gameObjectComponent::getID() {return myID;}

void DUO::gameObjectComponent::setID(int newID) {myID = newID;}

DUO::componentTypes DUO::gameObjectComponent::getType() {return myType;}

DUO::transformComponent::transformComponent(double newX, double newY, double newXScale, double newYScale, double newRotation, int newID, DUO::gameObject* newObject) : rotation(newRotation), gameObjectComponent(newID, newObject) {

    position.setVector(newX, newY);
    scale.setVector(newXScale, newYScale);

}

void DUO::transformComponent::setPosition(double x, double y) {position.setVector(x, y);}

DUO::vector DUO::transformComponent::getPosition() {return position;}

DUO::vector DUO::transformComponent::getScale() {return scale;}

double DUO::transformComponent::getRotation() {return rotation;}

bool DUO::transformComponent::translate(double xInc, double yInc) {

    try {

        position.increment(xInc, yInc);
        return true;

    } catch (const char* msg) {

        std::cout << msg << std::endl;
        return false;

    }

}

bool DUO::transformComponent::rescale(double xScale, double yScale) {
    
    try
    {
        scale.setVector(xScale, yScale);
        return true;
    }
    catch(const std::exception& e)
    {
        return false;
        std::cerr << e.what() << '\n';
    }

    return true;
    
}

bool DUO::transformComponent::rotate(double newRotation) {

    try {

        rotation += newRotation;
        return true;

    } catch (const char* msg) {

        std::cout << msg << std::endl;
        return false;

    }

}

DUO::renderComponent::renderComponent(int newID, DUO::gameObject* newObject, double width, double height)
    : DUO::gameObjectComponent(newID, newObject) {

        myTransform = myObject->getTransform();

        dimensions.setVector(width, height);
        myType = DUO::RENDERER;

}

DUO::vector DUO::renderComponent::getDimensions() {return dimensions;}

void DUO::renderComponent::setDimensions(double newWidth, double newHeight) {dimensions.setVector(newWidth, newHeight);}


DUO::polygonRenderer::polygonRenderer(int newID, DUO::gameObject* newObject, double width, double height, int newR, int newG, int newB, int sides) : 
renderComponent(newID, newObject, width, height), r(newR), g(newG), b(newB), numberOfSides(sides) {}

void DUO::polygonRenderer::update() {

    double x{myTransform->getPosition().getXComponent()};
    double y{myTransform->getPosition().getYComponent()};

    double width{dimensions.getXComponent() * myTransform->getScale().getXComponent()};

    if (isFilled) {

        DUO::fillPolygon(numberOfSides, width, x, y, r, g, b, myObject->getRenderer(), myTransform->getRotation());

    } else {

        DUO::drawPolygon(numberOfSides, width, x, y, r, g, b, myObject->getRenderer(), myTransform->getRotation());

    }

}