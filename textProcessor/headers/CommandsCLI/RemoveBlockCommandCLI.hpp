/**
 * @file RemoveBlockCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the RemoveBlockCommand.
 */
#pragma once
#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the RemoveBlockCommand.
 */
class RemoveBlockCommandCLI : public CommandsCLI {

 public:
    RemoveBlockCommandCLI() = default;
    ~RemoveBlockCommandCLI() override = default;

    void success() override;
    string getBlockName();
};