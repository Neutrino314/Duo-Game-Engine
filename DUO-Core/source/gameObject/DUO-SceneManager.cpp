#include "DUO-Scene.h"
#include "DUO-GameObject.h"
#include "DUO-SceneManager.h"
#include "DUO-ObjectManager.h"

#include <runtime/DUO-application.h>
#include <utils/stringUtils.h>
#include <yaml/parser.h>

#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <dlfcn.h>

DUO::scene* DUO::sceneManager::curScene = new DUO::scene(0);

std::string DUO::sceneManager::curScenePath = "NULL";

std::vector<std::pair<std::size_t, std::string>> DUO::sceneManager::sceneIDNameVect;

void DUO::sceneManager::refreshObjs(DUO::scene* scn)
{

    std::size_t i = 0;

    while (i < scn->objectVect.size())
    {

        if (scn->objectVect[i] == nullptr)
        {

            scn->objectVect.erase(scn->objectVect.begin() + i);

        } else
        {

            scn->objectVect[i]->setID(static_cast<int>(i));
            i++;

        }

    }

    scn->nextObjectID = scn->objectVect.size();

}

void DUO::sceneManager::addObject(DUO::scene* scn)
{

    scn->objectVect.emplace_back(std::unique_ptr<DUO::gameObject>(new DUO::gameObject(scn->nextObjectID)));
    scn->nextObjectID++;

}

void DUO::sceneManager::removeObject(DUO::scene* scn, std::size_t objID)
{

    if (objID >= scn->objectVect.size())
        return;

    scn->objectVect.erase(scn->objectVect.begin() + objID);
    
    for (std::size_t i = 0; i < scn->objectVect.size(); i++)
    {

        if (scn->objectVect[i] != nullptr)
        {

        scn->objectVect[i]->setID(i);

        }

    }

}

DUO::gameObject* DUO::sceneManager::getObject(std::size_t ID) 
{

    if (ID >= DUO::sceneManager::curScene->objectVect.size())
    {

        return nullptr;
        
    } else 
    {

        return DUO::sceneManager::curScene->objectVect[ID].get();

    }

}

void DUO::sceneManager::addScene(DUO::application &app, std::string path)
{

    

}

void DUO::sceneManager::loadScene(std::string path, SDL_Renderer* renderer)
{

    DUO::sceneParser scnLoader(path);
    scnLoader.parse();

    signed long curObject(-1);

    if (DUO::sceneManager::curScene->objectVect.empty())
    {


    }
    else
    {
        
        curScene->objectVect.clear();
        curScene->nextObjectID = 0;

    }

    for (std::size_t i = 0; i < scnLoader.getObjectAmount(); i++)
    {

        std::string type = scnLoader.getObjectType(i);
        if (type == "gameObject")
        {

            addObject(curScene);
            curObject++;
            curScene->objectVect[curObject]->myVel = scnLoader.getVector2("myVel", i);

        }
        else if (type == "Transform")
        {

            curScene->objectVect[curObject]->myTransform->pos = scnLoader.getVector2("position", i);
            curScene->objectVect[curObject]->myTransform->scale = scnLoader.getVector2("scale", i);
            curScene->objectVect[curObject]->myTransform->rotation = scnLoader.getVal<float>("rotation", i, 0.0f);

        }
        else if (type == "polygonRenderer")
        {
            
            DUO::objectManager::addComponent<DUO::polygonRenderer>(curScene->objectVect[curObject].get(), DUO::RENDERER);
            DUO::polygonRenderer* tempRenderer = DUO::objectManager::getComponent<DUO::polygonRenderer>(curScene->objectVect[curObject].get());

            tempRenderer->dimensions = scnLoader.getVector2("dimensions", i);
            tempRenderer->isFilled = scnLoader.getVal<bool>("isFilled", i, true);
            tempRenderer->numOfSides = scnLoader.getVal<std::size_t>("numOfSides", i, 0);
            tempRenderer->setTransform(curScene->objectVect[curObject]->myTransform.get());

            std::get<0>(tempRenderer->colour) = scnLoader.getVal<short>("r", i, 0);
            std::get<1>(tempRenderer->colour) = scnLoader.getVal<short>("g", i, 0);
            std::get<2>(tempRenderer->colour) = scnLoader.getVal<short>("b", i, 0);
            
        }
        else if (type == "spriteRenderer")
        {

            DUO::objectManager::addComponent<DUO::spriteRenderer>(curScene->objectVect[curObject].get(), DUO::RENDERER);
            DUO::spriteRenderer* tempRenderer = DUO::objectManager::getComponent<DUO::spriteRenderer>(curScene->objectVect[curObject].get());

            tempRenderer->dimensions = scnLoader.getVector2("dimensions", i);
            tempRenderer->setTransform(curScene->objectVect[curObject]->myTransform.get());
            tempRenderer->myPath = scnLoader.getVal<std::string>("path", i, "");

        }

    }

    curScene->setup(renderer);

}
