#include "stringUtils.h"
#include <string>
#include <iostream>
#include <vector>
#include <regex>

bool DUO::stringContainsString(std::string targetStr, std::string pattern)
{

    if (std::regex_match(targetStr, std::regex("(.*)(" + pattern + ")(.*)"))) //uses std::regex_match to check whether targetStr contains the pattern provided if so the function returns true;
    {

        return true;

    }
    else 
    {

        return false;

    }

}

bool DUO::strContainsChar(std::string targetStr, const char delimiter)
{

    for (const auto symbol : targetStr) //loops through each char in targetStr
    {

        if (symbol == delimiter) //if the character matches the delimiter it returns true;
            return true;
        else
            continue;

    }

    return false;

}

std::string DUO::removeChar(std::string targetStr, const char delimiter)
{

    std::string finalStr(""); //empty string that will be returned

    for (const auto symbol : targetStr) //loops through each char in targetStr
    {

        if (symbol == delimiter) //if the symbol == the delimiter then continue the loop
            continue;
        else //add the character to finalStr
            finalStr += symbol;

    }

    return finalStr; //return finalStr

}

std::vector<std::string> DUO::split(std::string& targetStr, const char delimiter)
{

    std::stringstream ss(targetStr);

    std::string curToken = "";

    std::vector<std::string> returnVect;

    while (std::getline(ss, curToken, delimiter))
    {

        returnVect.emplace_back(curToken);

    }

    return returnVect;

}

std::size_t DUO::countInstanceOf(const char delimiter, const std::string& targetStr)
{

    std::size_t retCount(0);

    for (const auto token : targetStr)
    {

        if (token == delimiter)
            retCount++;
        else
            continue;

    }

    return retCount;

}

bool DUO::firstNonEmptyChar(const char delimiter, const std::string& targetStr)
{

    if (targetStr[0] == delimiter)
        return true;
    else
        return false;

}

void DUO::removePattern(std::string& targetStr, std::string pattern)
{

    std::regex regPattern(pattern);

    targetStr = std::regex_replace(targetStr, regPattern, "");

}