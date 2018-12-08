#pragma once

#include "DUO-GameObject.h"
#include "DUO-GameObjectComponent.h"
#include "DUO-Utils.h"
#include <memory>
#include <typeinfo>

namespace DUO {

    class objectManager {

    public:

        template <typename T>
        static std::shared_ptr<T> getComp(DUO::gameObject* obj);

        template <typename T>
        static void addComp(DUO::broadType key1, DUO::gameObject* obj);

    };

}

template <typename T>

void DUO::objectManager::addComp(DUO::broadType key1, DUO::gameObject* obj) {

    switch (key1) {

    case DUO::BASE:

        obj->compMap[DUO::BASE][typeid(T).name()] = obj->curRenderID;
        obj->componentVect.push_back(std::make_shared<T>(obj->curComponentID, obj));
        obj->curComponentID++;
        break;

    case DUO::RENDERER:

        obj->compMap[DUO::RENDERER][typeid(T).name()] = obj->curRenderID;
        obj->renderComponentVect.push_back(std::make_shared<T>(obj->curRenderID, obj));
        obj->curRenderID++;
        break;

    default:

        obj->compMap[DUO::BASE][typeid(T).name()] = obj->curRenderID;
        obj->componentVect.push_back(std::make_shared<T>(obj->curComponentID, obj));
        obj->curComponentID++;
        break;

    }

}

template <typename T>

std::shared_ptr<T> DUO::objectManager::getComp(DUO::gameObject* obj) {

    auto foundKey = obj->compMap[DUO::BASE].find(typeid(T).name());

    if (foundKey != obj->compMap[DUO::BASE].end()) {

        int index = obj->compMap[DUO::BASE][typeid(T).name()];

        return std::dynamic_pointer_cast<T>(obj->componentVect[index]);

    }

    foundKey = obj->compMap[DUO::RENDERER].find(typeid(T).name());

    if (foundKey != obj->compMap[DUO::RENDERER].end()) {

        int index = obj->compMap[DUO::BASE][typeid(T).name()];

        return std::dynamic_pointer_cast<T>(obj->renderComponentVect[index]);

    }

    return nullptr;

}