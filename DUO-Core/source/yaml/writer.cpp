#include "writer.h"

#include <utils/fileUtils.h>
#include <utils/stringUtils.h>

#include <string>
#include <vector>
#include <fstream>

DUO::yamlWriter::yamlWriter(std::string path) : filePath(path)
{

    std::vector<std::string> lines = DUO::fileHandler::extractLines(path);

    std::vector<std::string> tempKeyVal;

    for (auto line : lines)
    {

        tempKeyVal = DUO::splitFirst(':', line);

        tempKeyVal = DUO::removeEmpty(tempKeyVal);

        keyVal[tempKeyVal[0]] = tempKeyVal[1];

    }

}

void DUO::yamlWriter::write(std::string tag, std::string data)
{

    keyValIter = keyVal.find(tag);

    if (keyValIter != keyVal.end())
    {

        keyVal[tag] = data;

        std::ofstream ofs(filePath , std::ios::trunc);

        for (const auto& line : keyVal)
        {

           ofs << line.first << ": " << line.second << std::endl;

        }

        ofs.close();

    }
    else
    {

        keyVal[tag] = data;
            
        std::ofstream ofs(filePath , std::ios::app);

        ofs << std::endl << tag.c_str() << ": " << keyVal[tag].c_str() <<  std::endl;

        ofs.close();

    }

}

void DUO::yamlWriter::print()
{

    for (const auto& line : keyVal)
    {
        
        std::cout << line.first << ": " << line.second << std::endl;

    }

}