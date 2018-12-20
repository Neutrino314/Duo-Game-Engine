#pragma once

#include "DUO-Scene.h"
#include "DUO-GameObject.h"
#include <vector>

namespace DUO
{

class sceneManager
{

private:

public:

    static void refreshObjs(DUO::scene* scn); //removes all objects that are nullptrs from the object vector of a scene

    static void addObject(DUO::scene* scn); //adds an object to a scene

    static void removeObject(DUO::scene* scn, std::size_t objID); //removes an object from a scene

};

}