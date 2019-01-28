#pragma once

#include <utils/fileUtils.h>
#include <utils/stringUtils.h>

#include <map>
#include <vector>
#include <string>
#include <fstream>

namespace DUO
{

class yamlWriter
{

private:

    std::string filePath;

    std::map<std::string, std::string> keyVal;
    std::map<std::string, std::string>::const_iterator keyValIter;

public:

    yamlWriter(std::string path = "");

    void print();

    template <typename T>
    void write(std::string tag, T data) 
    {

        keyValIter = keyVal.find(tag);

        if (keyValIter != keyVal.end())
        {

            keyVal[tag] = std::to_string(data);

            std::ofstream ofs(filePath , std::ios::trunc);

            if (!ofs)
            {

                std::cerr << "file not found!\n";
                return;

            }

            for (const auto& line : keyVal)
            {

                ofs << line.first << ": " << line.second << std::endl;

            }

            ofs.close();

        }
        else
        {
            
            keyVal[tag] = std::to_string(data);
            
            std::ofstream ofs(filePath , std::ios::app);

            if (!ofs)
            {

                std::cerr << "file not found!\n";
                return;

            }

            ofs << tag << ": " << keyVal[tag] <<  std::endl;

        }
        

    }

    void write(std::string tag, std::string data);

};

}