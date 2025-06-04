/**
 * @file Macro.hpp
 * @author MK
 * @brief A class to represent a macro, which is a sequence of commands.
 * @version 0.1
 * @date 2025-05-26
 */
#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

class Macro {

 public:
    Macro() = delete;
    Macro(string macroName, vector<string> commandNames) 
        : macroName(macroName), commandNames(commandNames) {}

    vector<string> getCommandNames();
    string getName();

    private:
        vector<string> commandNames;
        string macroName;
};