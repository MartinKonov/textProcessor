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
    void error(string message = "") override;
    void errorNoActiveDocument();
    string getBlockName();
    void blockExists();
    size_t getStartLineIndex();
    size_t getEndLineIndex();
    void errorUndo(string message);
    void successUndo();
};