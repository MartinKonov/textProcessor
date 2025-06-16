/**
 * @file CreateBlockCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the CreateBlockCommand.
 */
#pragma once

#include "CommandsCLI.hpp"



/**
 * @brief A class to handle input and output operations for the CreateBlockCommand.
 */
class CreateBlockCommandCLI : public CommandsCLI {
 
 public:
    CreateBlockCommandCLI() = default;
    ~CreateBlockCommandCLI() override = default;

    void success() override;
    string getBlockName();
    size_t getStartLineIndex();
    size_t getEndLineIndex();
    void successUndo();
};