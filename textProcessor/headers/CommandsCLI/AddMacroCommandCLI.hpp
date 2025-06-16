/**
 * @file AddMacroCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the AddMacroCommand.
 */
#pragma once

#include "CommandsCLI.hpp"
#include <vector>

using std::vector;

/**
 * @class AddMacroCommandCLI
 * @brief A class to handle input and output operations for the AddMacroCommand.
 */
class AddMacroCommandCLI : public CommandsCLI {
public:
    AddMacroCommandCLI() = default;
    ~AddMacroCommandCLI() override = default;

    void success() override;
    void error(string message = "") override;
    
    string getMacroName();
    vector<string> getCommandNames();
    void nothingToUndo();
    void successUndo();
};
