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

private:

    static std::string curScenePath; //the path to where the current scene is being stored

    static std::vector<std::pair<std::size_t, std::string>> sceneIDNameVect; //a vector of std::pairs where the ID of a scene is linked to it's path

public:

    static DUO::scene* curScene; //the current scene that will be updated and rendered by the application class

    static void refreshObjs(DUO::scene* scn); //removes all objects that are nullptrs from the object vector of a scene

    static void addObject(DUO::scene* scn); //adds an object to a scene

    static DUO::gameObject* getObject(std::size_t objID); //gets a raw pointer to an object in the current scene

    static void removeObject(DUO::scene* scn, std::size_t objID); //removes an object from a scene

    static void addScene(DUO::application &app, std::string path); //creates a new empty scene and serializes it to a file with the specified path

    static void removeScene(std::size_t ID); //deletes the scene with the appropriate ID

    static void removeScene(std::string path); //deletes a scene with the given path

    static void saveScene(DUO::scene* scn); //serializes a scene to a text file

    static void loadScene(std::size_t ID); //loads a scene with the given ID

    static void loadScene(std::string name, SDL_Renderer* renderer); //loads a scene with the given name

};

}