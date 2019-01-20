#include "DUO-Scene.h"
#include "DUO-GameObject.h"
#include "DUO-SceneManager.h"
#include <runtime/DUO-application.h>
#include <vector>
#include <iostream>
#include <memory>
#include <string>

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

