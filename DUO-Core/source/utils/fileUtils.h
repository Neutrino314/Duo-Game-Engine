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

    };

} 