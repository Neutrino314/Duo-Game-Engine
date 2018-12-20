#include "DUO-Scene.h"
#include "DUO-GameObject.h"
#include "DUO-SceneManager.h"
#include <vector>
#include <iostream>
#include <memory>

void DUO::sceneManager::refreshObjs(DUO::scene* scn)
{

    std::size_t i = 0;

    while (i < scn->objectVect.size())
    {

        if (scn->objectVect[i] == nullptr)
        {

            scn->objectVect.erase(scn->objectVect.begin() + i);
            std::cout << "erased\n";

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

    scn->objectVect.emplace_back(std::unique_ptr<DUO::gameObject>(new DUO::gameObject(scn->nextObjectID, scn->myRenderer)));
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



