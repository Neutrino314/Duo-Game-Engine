#include <utils/stringUtils.h>
#include <utils/fileUtils.h>
#include "parser.h"

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>

DUO::sceneParser::sceneParser(std::string filePath)
{

    if (DUO::fileHandler::getExtent(filePath) != ".yaml" && DUO::fileHandler::getExtent(filePath) != ".yml")
    {

        std::cout << "failed\n";
        return;

    }

    lines = DUO::fileHandler::extractLines(filePath);

}

void DUO::sceneParser::printLines()
{

    for (const auto string : lines)
    {

        std::cout << string << std::endl;

    }

}

void DUO::sceneParser::updateObject(std::string& line)
{

    if (DUO::stringContainsString(line, "--- &"))
        {

            DUO::removePattern(line, "--- &");

            std::istringstream iss(line);

            std::size_t id(0);

            iss >> id;

            curID = id;      

            std::vector<std::string> temp;

            objectDict[curID] = temp;     

        }

}

void DUO::sceneParser::parse()
{

    for (auto line : lines)
    {

        updateObject(line);

        objectDict[curID].emplace_back(line);

    }

}

void DUO::sceneParser::printDict()
{


}

std::string DUO::sceneParser::getVal(std::string tag, std::size_t objID)
{

    objectDict.find(objID);

    for (auto line : objectDict[objID])
    {

        std::vector<std::string> keyVal = DUO::splitFirst(':', line);

        keyVal = DUO::removeEmpty(keyVal);

        if (keyVal.size() == 2)
        {

            keyVal[0] = DUO::removeWhiteSpace(keyVal[0]);

        }

        if (keyVal.size() == 2 && keyVal[0] == tag)
        {

            return keyVal[1];

        }

    }

    return "";

}

DUO::vector2 DUO::sceneParser::getVector2(std::string tag, std::size_t objID)
{
    for (auto line : objectDict[objID])
    {

        std::vector<std::string> keyVal = DUO::splitFirst(':', line);

        keyVal = DUO::removeEmpty(keyVal);

        if (keyVal.size() == 2)
        {

            keyVal[0] = DUO::removeWhiteSpace(keyVal[0]);

            if (keyVal[0] == tag)
            {

                keyVal[1] = DUO::removeChar(keyVal[1], '{');
                keyVal[1] = DUO::removeChar(keyVal[1], '}');

                std::vector<std::string> elements = DUO::split(keyVal[1], ',');
                elements[0] = DUO::removeWhiteSpace(elements[0]);
                elements[1] = DUO::removeWhiteSpace(elements[1]);

                DUO::removePattern(elements[0], "x:");
                DUO::removePattern(elements[1], "y:");

                DUO::vector2 vect{std::stof(elements[0]), std::stof(elements[1])};

                return vect;

            }

        }

    }

    DUO::vector2 vect{0.0f, 0.0f};

    return vect;
}