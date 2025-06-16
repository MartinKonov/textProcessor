/**
 * @file AddLineCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the AddLineCommand.
 * @version 0.1
 * @date 2025-05-29
 */

#pragma once
#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the AddLineCommand.
 */
class AddLineCommandCLI : public CommandsCLI {

 public:
    AddLineCommandCLI() = default;
    ~AddLineCommandCLI() override = default;
    
    string getLineInput();
    void nothingChanged();
    void success() override;
};