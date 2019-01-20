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

    typedef std::map<std::size_t, std::vector<std::string>>::const_iterator mapIterator;

    for (mapIterator iter = objectDict.begin(); iter != objectDict.end(); iter++)
    {

        for (auto line : iter->second)
        {

            std::cout << line << std::endl;

        }

    }

}


