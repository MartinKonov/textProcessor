#pragma once
#include "Command.hpp"
#include "../Block/BlockRegister.hpp"
#include "../CommandsCLI/CreateBlockCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"



class CreateBlockCommand : public Command {

 public:
    CreateBlockCommand() = delete;
    CreateBlockCommand(CreateBlockCommandCLI* createBlockCommandCLI, BlockRegister* blockRegister, ActiveDocument* activeDocument);
    CreateBlockCommand(CreateBlockCommand& other) = delete;
    CreateBlockCommand& operator=(CreateBlockCommand& other) = delete;

    string getName() const override;
    void execute() override;
    void undo() override;

 private:
    string nameOfLastBlockCreated;
    BlockRegister* blockRegister;
    CreateBlockCommandCLI* createBlockCommandCLI;
    ActiveDocument* activeDocument;
};