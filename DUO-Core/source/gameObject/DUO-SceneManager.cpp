#include "DUO-Scene.h"
#include "DUO-GameObject.h"
#include "DUO-SceneManager.h"
#include "DUO-ObjectManager.h"
#include "userDefinedComponent.h"

#include <runtime/DUO-application.h>
#include <utils/stringUtils.h>
#include <yaml/parser.h>
#include <graphics/camera.h>

#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <dlfcn.h>

DUO::scene* DUO::sceneManager::curScene = new DUO::scene(0);

std::map<std::string, DUO::createComp_t*> DUO::sceneManager::compFactoryMap;

void* DUO::sceneManager::compLib = NULL;

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

void DUO::sceneManager::addScene(std::string path)
{

    

}

void DUO::sceneManager::loadScene(std::string path)
{

    DUO::sceneParser scnLoader(path);
    scnLoader.parse();

    std::map<int, int> goMap;

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

        std::cout << scnLoader.getObjectType(i) << std::endl;

        std::string type = scnLoader.getObjectType(i);
        if (type == "camera")
        {

            curScene->sceneCam = new DUO::camera(scnLoader.getVal<bool>("hasTarget", i, false));
            curScene->sceneCam->setTargetID(scnLoader.getVal<int>("targetID", i, 0));
            curScene->sceneCam->setOrigin(scnLoader.getVector2("origin", i));

        }
        else if (type == "gameObject")
        {

            addObject(curScene);
            curObject++;
            goMap[i] = curObject;
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

            tempRenderer->m_colour.r = scnLoader.getVal<short>("r", i, 0);
            tempRenderer->m_colour.g = scnLoader.getVal<short>("g", i, 0);
            tempRenderer->m_colour.b = scnLoader.getVal<short>("b", i, 0);
            
        }
        else if (type == "spriteRenderer")
        {

            DUO::objectManager::addComponent<DUO::spriteRenderer>(curScene->objectVect[curObject].get(), DUO::RENDERER);
            DUO::spriteRenderer* tempRenderer = DUO::objectManager::getComponent<DUO::spriteRenderer>(curScene->objectVect[curObject].get());

            tempRenderer->dimensions = scnLoader.getVector2("dimensions", i);
            tempRenderer->setTransform(curScene->objectVect[curObject]->myTransform.get());
            tempRenderer->myPath = scnLoader.getVal<std::string>("path", i, "");

        }
        else
        {
            
            for (const auto importedType : compFactoryMap)
            {

                if (type == importedType.first)
                {

                    DUO::userComponent* tempComp = (*importedType.second)();

                    tempComp->load(curScene->objectVect[curObject].get(), curScene->objectVect[curObject].get()->nextCompID);
                    curScene->objectVect[curObject]->nextCompID++;

                    curScene->objectVect[curObject]->componentVect.emplace_back(std::unique_ptr<DUO::userComponent>(tempComp));

                    break;

                }

            }

        }
        
    }

    curScene->setup(DUO::application::mainRenderer);

    curScene->sceneCam->loadTarget(curScene->objectVect[goMap[curScene->sceneCam->getTargetID()]].get());\

    curScene->sceneCam->setup();

}

void DUO::sceneManager::loadTypes(std::string compPath, std::string libPath)
{

    DUO::sceneParser parser(compPath);

    parser.parse();

    compLib = dlopen(libPath.c_str(), RTLD_LAZY);
    if (!compLib)
    {

        std::cerr << "Error opening component library: " << dlerror() << "\n";
        exit(1);

    }

    dlerror();

    std::string createName = "";

    std::string compTypename = "";
    
    for (std::size_t i = 0; i < parser.getObjectAmount(); i++)
    {

        createName = parser.getVal("factoryName", i);
        compTypename = parser.getVal("Name", i);

        compFactoryMap[compTypename] = (DUO::createComp_t*) dlsym(compLib, createName.c_str());

        const char* dlsym_error = dlerror();

        if (dlsym_error) {
            
            std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
            
            std::exit(1);
        
        }

    }

}

void DUO::sceneManager::unloadTypes()
{

    dlclose(compLib);

}
