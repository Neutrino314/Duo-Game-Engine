#include "DUO-Utils.h"
#include <maths/DUO-Vector2.h>
#include "DUO-GameObjectComponent.h"
#include "DUO-GameObject.h"
#include "DUO-Scene.h"
#include <graphics/DUO-Graphics.h>
#include <runtime/DUO-Keyboard.h>
#include <iostream>
#include <memory>

DUO::gameObjectComponent::gameObjectComponent(int newID) : myID(newID)
{

    myBroadType = DUO::BASE; //changes the myBroadType variable to DUO::BASE
    myType = typeid(this).name(); //sets the myType variable

}

int DUO::gameObjectComponent::getID() {return myID;} //returns the comp's ID

void DUO::gameObjectComponent::setID(int ID) {myID = ID;} //sets the comp's ID

const char* DUO::gameObjectComponent::getType() {return myType;} //returns myType

DUO::transformComponent::transformComponent(int newID, float x, float y, float xScale, float yScale, float newRot) : gameObjectComponent(newID), rotation(newRot)
{

    myBroadType = DUO::TRANSFORM; //changes the broadType variable to a transform
    myType = typeid(this).name(); //sets the type of the component via the typeid() operator

    pos.setVector(x, y); //sets the position to the new components
    scale.setVector(xScale, yScale); //changes the scale vector to the new components

}

void DUO::transformComponent::translate(float x, float y) {pos.increment(x, y);} //increments the position vector

DUO::renderComponent::renderComponent(int newID, float width, float height, DUO::transformComponent* newTransform) : gameObjectComponent(newID), myTransform(newTransform)
{

    myBroadType = DUO::RENDERER; //changes the broad type to that of a RENDERER
    myType = typeid(this).name(); //sets the type of the component via the typeid() operator

    dimensions.setVector(width, height); //sets the new dimensions

}

void DUO::renderComponent::setTransform(DUO::transformComponent* transform)
{

    myTransform = transform;

}

DUO::polygonRenderer::polygonRenderer(int newID) : renderComponent(newID)
{

    myBroadType = DUO::RENDERER; //changes the broad type to that of a RENDERER
    myType = typeid(this).name(); //sets the type of the component via the typeid() operator

}

DUO::polygonRenderer::polygonRenderer(int newID, std::size_t sidesAmount, bool filled, DUO::transformComponent* newTransform, float width, float height, short r, short g, short b) : renderComponent(newID, width, height, newTransform), numOfSides(sidesAmount)
{

    myBroadType = DUO::RENDERER; //changes the broad type to that of a RENDERER
    myType = typeid(this).name(); //sets the type of the component via the typeid() operator

    std::get<0>(colour) = r;
    std::get<1>(colour) = g;
    std::get<2>(colour) = b;

    isFilled = filled;

}

void DUO::polygonRenderer::update(DUO::vector2 displayPos, SDL_Renderer* renderer)
{

    if (isFilled)
        DUO::fillPolygon(numOfSides, dimensions.x, displayPos.x, displayPos.y, std::get<0>(colour), std::get<1>(colour), std::get<2>(colour), renderer, myTransform->rotation);
    else
        DUO::drawPolygon(numOfSides, dimensions.x, displayPos.x, displayPos.y, std::get<0>(colour), std::get<1>(colour), std::get<2>(colour), renderer, myTransform->rotation);

}

DUO::spriteRenderer::spriteRenderer(int newID) : renderComponent(newID)
{

    myBroadType = DUO::RENDERER;
    myType = typeid(this).name();

}

DUO::spriteRenderer::spriteRenderer(int newID, std::string newPath, float width, float height, DUO::transformComponent* newTransform) : renderComponent(newID, width, height, newTransform)
{

    myBroadType = DUO::RENDERER;
    myType = typeid(this).name();

}

void DUO::spriteRenderer::setup(SDL_Renderer* renderer)
{

    myTexture = DUO::loadImage(myPath, renderer);

    int x, y;

    SDL_QueryTexture(myTexture, NULL, NULL, &x, &y);

    nativeDimensions.setVector(x, y);

}

void DUO::spriteRenderer::update(DUO::vector2 displayPos, SDL_Renderer* renderer)
{

    int x = static_cast<int>(displayPos.x -  (dimensions.x / 2));
    int y = static_cast<int>(displayPos.y - (dimensions.y / 2));

    SDL_Rect tempRect {x, y, static_cast<int>(dimensions.getXComponent()), static_cast<int>(dimensions.getYComponent())};

    SDL_Point centre{x, y};

    SDL_RenderCopyEx(renderer, myTexture, NULL, &tempRect, myTransform->rotation, NULL, SDL_FLIP_NONE);

}