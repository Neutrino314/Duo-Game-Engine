#include "DUO-GameObjectComponent.h"
#include "DUO-GameObject.h"
#include "userDefinedComponent.h"

#include <typeinfo>

DUO::userComponent::userComponent(int newID, DUO::gameObject* newObj) : gameObjectComponent(newID), myObj(newObj)
{

    myType = typeid(this).name();
    myBroadType = DUO::USERDEFINED;

}

DUO::userComponent::~userComponent()
{

    delete myType;
    myType = nullptr;

}

void DUO::userComponent::load(DUO::gameObject* obj, std::size_t ID)
{

    myObj = obj;
    myID = ID;

}

void DUO::userComponent::update()
{



}

void DUO::userComponent::setup()
{


}