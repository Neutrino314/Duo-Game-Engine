#pragma once

#include "DUO-GameObject.h"
#include "DUO-GameObjectComponent.h"
#include "DUO-Scene.h"
#include "DUO-Utils.h"
#include <memory>
#include <typeinfo>
#include <vector>

namespace DUO 
{

    class objectManager
    {

        template <typename T>
        static T* getComponent(DUO::gameObject* obj);//gets a comp of type T from the object's component vectors

        template <typename T>
        static std::vector<T*> getComponents(DUO::gameObject* obj);//returns a std::vector of pointers to game object components of type T in an object

        template <typename T>
        static void addComponent(DUO::gameObject* obj, DUO::broadType broadCompType);//adds a component of type T with defaultt values to an object

        static void refresh(DUO::scene* scn); //removes any elements in the objectVect of a scene that are nullptrs

    };

}

template <typename T>
T* DUO::objectManager::getComponent(DUO::gameObject* obj)
{

    for (const auto& component : obj->componentVect) //iterates through each component in the object's component vector
    {

        if (component->getType() == typeid(T*).name()) //compares the components's "type" with that of the type T*
        {

            return component.get(); //if true then it returns a raw pointer to the comp

        }

    }

    for (const auto& component : obj->renderCompVect) //iterates through each component in the object's render component vector
    {

        if (component->getType() == typeid(T*).name()) //compares the components's "type" with that of the type T*
        {

            return component.get(); //if true then it returns a raw pointer to the comp

        }

    }

    return nullptr; //if the component was not found then return nullptr

}

template <typename T>
std::vector<T*> DUO::objectManager::getComponents(DUO::gameObject* obj)
{

    static std::vector<T*> components; //creating a static vector of components

    const char* typeString = typeid(T*).name(); //storing the type of T* as a char array

    for (const auto& component : obj->componentVect) //iterating through each component in the object's component vector
    {

        if (typeString == component->getType()) //if the typeString is equal to the comp's type 
        {

            components.emplace_back(component.get()); //add the comp's pointer to the component vector

        }

    }

    for (const auto& component : obj->renderCompVect) //iterating through each component in the object's render component vector
    {

        if (typeString == component->getType()) //if the typeString is equal to the comp's type
        {

            components.emplace_back(component.get()); //add the comp's pointer to the component vector

        }

    }

    return components; //returns the component vector

}

template <typename T>
void DUO::objectManager::addComponent(DUO::gameObject* obj, DUO::broadType broadCompType)
{

    switch (broadCompType)
    {

        case DUO::BASE:

            obj->componentVect.emplace_back(std::unique_ptr<T>(new T(obj->nextCompID, obj->myRenderer)));
            obj->nextCompID++;
            break;

        case DUO::RENDERER:

            obj->renderCompVect.emplace_back(std::unique_ptr<T>(new T(obj->nextCompID, obj->myRenderer)));
            obj->nextRenderCompID++;
            break;

        default:

            obj->componentVect.emplace_back(std::unique_ptr<T>(new T(obj->nextCompID, obj->myRenderer)));
            obj->nextCompID++;
            break;

    }

}
