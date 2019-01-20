#include "fileUtils.h"
#include "stringUtils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> DUO::fileHandler::extractLines(std::string path)
{

    std::ifstream file(path);

    std::string curLine = "";

    std::vector<std::string> lineVect;

    while (std::getline(file, curLine))
    {

        lineVect.emplace_back(curLine);

    }

    return lineVect;

}

std::string DUO::fileHandler::getExtent(std::string file)
{

    std::string extension;

    bool stopFound;

    for (char symbol : file)
    {

        if (symbol == '.')
        {

            stopFound = true;

            extension += symbol;

        }
        else if (stopFound)
        {

            extension += symbol;

        }
        else
        {

            continue;

        }

    }

    return extension;

}