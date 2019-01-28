#include "fileUtils.h"
#include "stringUtils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>

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

std::vector<std::string> DUO::fileHandler::getFiles(std::string path, std::string extension)
{

    std::vector<std::string> files;

    DIR* dirp = opendir(path.c_str());

    struct dirent * dp;

    while((dp = readdir(dirp)) != NULL)
    {

        files.push_back(dp->d_name);
    
    }
    
    closedir(dirp);

    std::vector<std::string> returnVect;

    for (const auto file : files)
    {

        if (DUO::fileHandler::getExtent(file) == extension)
            returnVect.emplace_back(file);

    }

    return returnVect;

}