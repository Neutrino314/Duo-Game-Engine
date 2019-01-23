#include <utils/stringUtils.h>
#include <maths/DUO-Vector2.h>
#include <utils/tupleUtils.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <type_traits>

#pragma once

namespace DUO
{

    struct yamlDict
    {

        std::string tag;
        std::map<std::string, std::string> keyValMap;

    };

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

        std::size_t getObjectAmount() {return objectDict.size();}

        std::string getObjectType(std::size_t objID);

        std::string getVal(std::string tag, std::size_t objID);

        DUO::vector2 getVector2(std::string tag, std::size_t objID);

        template <typename T>
        T getVal(std::string tag, std::size_t objID, T defaultVal)
        {

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

                    return DUO::fromString<T>(keyVal[1], defaultVal);

                }

            }

            return defaultVal;

        }

    };

}