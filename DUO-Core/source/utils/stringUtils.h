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

    std::size_t countInstanceOf(const char delimiter, const std::string& targetStr);

    bool firstNonEmptyChar(const char delimiter, const std::string& targetStr);

    void removePattern(std::string& targetStr, std::string pattern);

}