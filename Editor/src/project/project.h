#pragma once

#include <DUO-Engine.h>

#include <vector>
#include <string>

namespace DUO
{

class project
{

private:

    std::string projectName{""};

    std::string assetPath{""};

    std::string winTitle{""};

    std::string author{"anonymous"};

    DUO::vector2 windowDimensions{800.0f, 600.0f};

public:

    project();

    static void createProject(std::string path, std::string name);

    void load(std::string fullName);

    void resize(float x, float y);

    void setWinTitle(std::string newTitle);

};

}