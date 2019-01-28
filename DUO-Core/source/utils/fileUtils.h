#pragma once 

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

namespace DUO
{   

    class fileHandler
    {

    public:

        static std::vector<std::string> extractLines(std::string path);

        static std::string getExtent(std::string file);

        static std::vector<std::string> getFiles(std::string path, std::string extent);

    };

} 