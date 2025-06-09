#pragma once
#include "CommandsCLI.hpp"



class RemoveBlockCommandCLI : public CommandsCLI {

 public:
    RemoveBlockCommandCLI() = default;
    ~RemoveBlockCommandCLI() override = default;

    void success() override;
    void error(string message = "") override;

    string getBlockName();
    void blockDoesntExist();
    void removedBlockError();
    void errorUndo(string message);
};