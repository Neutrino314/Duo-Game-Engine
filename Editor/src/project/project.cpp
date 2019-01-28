#include "project.h"

#include <DUO-Engine.h>

#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>

DUO::project::project() {}

void DUO::project::createProject(std::string location, std::string name)
{

    std::string path = location + "\"" + name + "\"/";

    std::string command = "mkdir " + path;
    
    std::system(command.c_str());

    command = "cp \"yaml prototypes\"/project.yaml " + path;

    std::system(command.c_str());

    DUO::yamlWriter yml(location + name + "/project.yaml");

    yml.write("winTitle", name);

    yml.write("name", name);

    yml.write("assetPath", location + name + "/");

}

void DUO::project::load(std::string fullName)
{

    DUO::sceneParser ymlParser(fullName + "/project.yaml");

    ymlParser.parse();

    projectName = ymlParser.getVal("name", 0);

    assetPath = ymlParser.getVal("assetPath", 0);

    windowDimensions = ymlParser.getVector2("dimensions", 0);

    winTitle = ymlParser.getVal("winTitle", 0);

}