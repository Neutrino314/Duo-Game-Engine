#include <utils/stringUtils.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#pragma once

namespace DUO
{

    class sceneParser
    {

    private:

        std::map<std::size_t, std::vector<std::string>> objectDict;

        std::vector<std::string> lines;

        std::size_t curID{0};

        void updateObject(std::string& line);

    public:

        sceneParser(std::string filePath);

        void parse();

        void printLines();

        void printDict();

    };

}