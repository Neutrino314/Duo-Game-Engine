#include "DUO-Utils.h"
#include <maths/DUO-Vector2.h>
#include "DUO-GameObjectComponent.h"
#include "DUO-GameObject.h"
#include "DUO-Scene.h"
#include <graphics/DUO-Graphics.h>
#include <runtime/DUO-Keyboard.h>
#include <iostream>
#include <memory>

DUO::gameObjectComponent::gameObjectComponent(int newID, DUO::gameObject* newObject) : myObject(newObject), myType(DUO::BASE) {

    myID = myObject->getCurID(myType);

};

int DUO::gameObjectComponent::getID() {return myID;}

void DUO::gameObjectComponent::setID(int newID) {myID = newID;}

DUO::broadType DUO::gameObjectComponent::getType() {return myType;}

DUO::transformComponent::transformComponent(int newID, DUO::gameObject* newObject, double newX, double newY, double newXScale, double newYScale, double newRotation) : rotation(newRotation), gameObjectComponent(newID, newObject) {

    position.setVector(newX, newY);
    scale.setVector(newXScale, newYScale);

}

DUO::transformComponent::transformComponent(int newID, DUO::gameObject* newObject) : gameObjectComponent(newID, newObject){};

void DUO::transformComponent::setPosition(double x, double y) {position.setVector(x, y);}

DUO::vector2 DUO::transformComponent::getPosition() {return position;}

DUO::vector2 DUO::transformComponent::getScale() {return scale;}

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

DUO::renderComponent::renderComponent(int newID, DUO::gameObject* newObject) : gameObjectComponent(newID, newObject) {

    myTransform = myObject->getTransform();

    myType = DUO::RENDERER;

}

DUO::vector2 DUO::renderComponent::getDimensions() {return dimensions;}

void DUO::renderComponent::setDimensions(double newWidth, double newHeight) {dimensions.setVector(newWidth, newHeight);}


DUO::polygonRenderer::polygonRenderer(int newID, DUO::gameObject* newObject, double width, double height, int newR, int newG, int newB, int sides) : 
renderComponent(newID, newObject, width, height), r(newR), g(newG), b(newB), numberOfSides(sides) {}

DUO::polygonRenderer::polygonRenderer(int newID, DUO::gameObject* newObject) : renderComponent(newID, newObject) {}

void DUO::polygonRenderer::update(DUO::vector2 objectPos) {

    double x{myTransform->getPosition().getXComponent()};
    double y{myTransform->getPosition().getYComponent()};

    double width{dimensions.getXComponent() * myTransform->getScale().getXComponent()};

    if (isFilled) {

        DUO::fillPolygon(numberOfSides, width, objectPos.getXComponent(), objectPos.getYComponent(), r, g, b, myObject->getRenderer(), myTransform->getRotation());

    } else {

        DUO::drawPolygon(numberOfSides, width, objectPos.getXComponent(), objectPos.getYComponent(), r, g, b, myObject->getRenderer(), myTransform->getRotation());

    }

}

DUO::spriteRenderer::spriteRenderer(std::string path, int newID, DUO::gameObject* newObject, double width, double height) : renderComponent(newID, newObject, width, height) {

    myType = DUO::RENDERER;

    myTexture = DUO::loadImage(path, newObject->getRenderer());

    int x, y;

    SDL_QueryTexture(myTexture, NULL, NULL, &x, &y);

    dimensions.setVector(x, y);

}

DUO::spriteRenderer::spriteRenderer(int newID, DUO::gameObject* newObject) : renderComponent(newID, newObject) {}

void DUO::spriteRenderer::setPath(std::string newPath) {

    myTexture = DUO::loadImage(newPath, myObject->getRenderer());

    int x, y;

    SDL_QueryTexture(myTexture, NULL, NULL, &x, &y);

    dimensions.setVector(x, y);

}

void DUO::spriteRenderer::update(DUO::vector2 objectPos) {

    int x = static_cast<int>(objectPos.getXComponent());
    int y = static_cast<int>(objectPos.getYComponent());

    SDL_Rect tempRect {x, y, static_cast<int>(dimensions.getXComponent()), static_cast<int>(dimensions.getYComponent())};

    SDL_Point centre{x, y};

    SDL_RenderCopyEx(myObject->getRenderer(), myTexture, NULL, &tempRect, myTransform->getRotation(), NULL, SDL_FLIP_NONE);

}

void DUO::polygonRenderer::setColour(int newR, int newG, int newB) {

    r = newR;
    g = newG;
    b = newG;

}