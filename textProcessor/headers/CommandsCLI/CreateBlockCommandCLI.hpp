#pragma once

#include "CommandsCLI.hpp"




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