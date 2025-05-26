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
        string getMacroName();

    private:
        vector<string> commandNames;
        string macroName;
};