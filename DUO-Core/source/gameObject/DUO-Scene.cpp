#include "DUO-Utils.h"
#include "DUO-Scene.h"
#include "DUO-GameObject.h"
#include "DUO-GameObjectComponent.h"
#include <vector>
#include <memory>
#include <SDL2/SDL.h>

#include <graphics/camera.h>
#include <runtime/DUO-application.h>

DUO::scene::scene(int newID) : myID(newID)
{ //on instantiation myID is assigned the value of newID and the renderer pointer is assigned to the myRenderer object

    sceneCam = new DUO::camera(false);

    objectVect.emplace_back(std::unique_ptr<DUO::gameObject>(new DUO::gameObject(nextObjectID)));
//  ^---adding a new object to the object vector with curID as the ID and passing a pointer to myRenderer
    nextObjectID++;

    sceneCam->loadTarget(objectVect[0].get());

}

DUO::scene::~scene()
{

    delete sceneCam;
    sceneCam = nullptr;

}

void DUO::scene::setup(SDL_Renderer* renderer) 
{

    for (const auto& object : objectVect)  //foreach loop iterating through the object vector
    {

        if(object != nullptr)
        {
            object->setup(renderer); //calling the object's setup() method
        }

    }

}

void DUO::scene::update()
{

    for (const auto& object : objectVect)
    {

        if(object != nullptr)
        {
            object->update(); //calling the object's update() method
        }

    }
    
    sceneCam->update();

}

void DUO::scene::draw(float interpolation)
{

    sceneCam->calculateOffset(interpolation);

    for (const auto& object : objectVect) 
    {
        
        if (object != nullptr)
        {
            object->draw(interpolation, DUO::application::mainRenderer, sceneCam->getOffset()); //calling the object's draw method
        }

    }

}

int DUO::scene::getID()
{

    return myID;

}
