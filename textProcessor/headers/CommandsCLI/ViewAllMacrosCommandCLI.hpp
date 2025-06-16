/**
 * @file ViewAllMacrosCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the ViewAllMacrosCommand.
 */
#pragma once
#include "CommandsCLI.hpp"

/**
 * @class ViewAllMacrosCommandCLI
 * @brief A class to handle input and output operations for the ViewAllMacrosCommand.
 */
class ViewAllMacrosCommandCLI : public CommandsCLI {
public:
    ViewAllMacrosCommandCLI() = default;
    ~ViewAllMacrosCommandCLI() override = default;

    void success() override {};
    
    void showCurrentMacros(string serializedMacros);
};


