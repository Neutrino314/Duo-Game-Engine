#pragma once

#include <string>
#include <regex>
#include <vector>
#include <iostream>

namespace DUO
{

    bool stringContainsString(std::string targetStr, std::string pattern);

    bool strContainsChar(std::string targetStr, const char delimiter);

    std::string removeChar(std::string targetStr, const char delimiter);

    std::vector<std::string> split(std::string& targetStr, const char delimiter);

    std::vector<std::string> splitFirst(const char delimiter, const std::string& targetStr);

    std::size_t countInstanceOf(const char delimiter, const std::string& targetStr);

    bool firstNonEmptyChar(const char delimiter, const std::string& targetStr);

    void removePattern(std::string& targetStr, std::string pattern);

    template <typename T>
    T fromString(std::string targetStr)
    {

        std::istringstream iss(targetStr);
        T tempVal;
        if (!(iss >> tempVal))
        {

            T ret;
            return ret;

        }

        return tempVal;

    }

    void removeWhitespace(std::vector<std::string>& strVect);

    std::string removeWhiteSpace(std::string targetStr);

    std::vector<std::string> removeEmpty(std::vector<std::string> strVect);

}