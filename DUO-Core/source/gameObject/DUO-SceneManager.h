#pragma once

#include "DUO-Scene.h"
#include "DUO-GameObject.h"
#include <runtime/DUO-application.h>
#include <vector>
#include <map>
#include <string>

namespace DUO
{

class sceneManager
{

public:

    static DUO::scene* curScene; //the current scene that will be updated and rendered by the application class

    static void refreshObjs(DUO::scene* scn); //removes all objects that are nullptrs from the object vector of a scene

    static void addObject(DUO::scene* scn); //adds an object to a scene

    static void removeObject(DUO::scene* scn, std::size_t objID); //removes an object from a scene

    static void saveScene(DUO::scene* scn); //serializes a scene to a text file

    static void addScene(DUO::application &app, std::string path);

};

}