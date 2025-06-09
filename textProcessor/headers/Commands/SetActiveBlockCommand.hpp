#pragma once
#include "Command.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../Block/ActiveBlock.hpp"
#include "../CommandsCLI/SetActiveBlockCommandCLI.hpp"
#include "../Block/BlockRegister.hpp"



class SetActiveBlockCommand : public Command {

 public:
    SetActiveBlockCommand() = delete;
    SetActiveBlockCommand(SetActiveBlockCommandCLI* setActiveBlockCommandCLI, ActiveBlock* activeBlock, ActiveDocument* activeDocument, BlockRegister* blockRegister);
    SetActiveBlockCommand(SetActiveBlockCommand& other) = delete;
    SetActiveBlockCommand& operator=(SetActiveBlockCommand& other) = delete;
    ~SetActiveBlockCommand() override;

    string getName() const override;
    void execute() override;
    void undo() override;


 private:
    Block* previousActiveBlock;
    ActiveBlock* activeBlock;
    ActiveDocument* activeDocument;
    SetActiveBlockCommandCLI* setActiveBlockCommandCLI;
    BlockRegister* blockRegister;
};