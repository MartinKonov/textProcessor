#pragma once
#include "Command.hpp"
#include "../Block/BlockRegister.hpp"
#include "../CommandsCLI/RemoveBlockCommandCLI.hpp"
#include "../Document/DocumentRegister.hpp"


class RemoveBlockCommand : public Command {

 public:
    RemoveBlockCommand() = delete;
    RemoveBlockCommand(RemoveBlockCommandCLI* removeBlockCommandCLI,BlockRegister* blockRegister, DocumentRegister* documentRegister);
    RemoveBlockCommand(RemoveBlockCommand& other) = delete;
    RemoveBlockCommand& operator=(RemoveBlockCommand& other) = delete;
    ~RemoveBlockCommand() override;

    string getName() const override;
    void execute() override;
    void undo() override;

 private:
    Block* removedBlock;
    BlockRegister* blockRegister;
    RemoveBlockCommandCLI* removeBlockCommandCLI;
    DocumentRegister* documentRegister;
};