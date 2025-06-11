#pragma once
#include "Command.hpp"
#include "../Block/ActiveBlock.hpp"
#include "../Block/BlockRegister.hpp"
#include "../CommandsCLI/RemoveActiveBlockCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"


class RemoveActiveBlockCommand : public Command {
    public:
    RemoveActiveBlockCommand() = delete;
    RemoveActiveBlockCommand(RemoveActiveBlockCommandCLI* cli, ActiveBlock* activeBlock, ActiveDocument* activeDocument);
    ~RemoveActiveBlockCommand() override;
    RemoveActiveBlockCommand(const RemoveActiveBlockCommand& other) = delete;
    RemoveActiveBlockCommand& operator=(const RemoveActiveBlockCommand& other) = delete;

    string getName() const override;
    void execute() override;
    void undo() override;

private:
    RemoveActiveBlockCommandCLI* cli;
    ActiveBlock* activeBlock;
    ActiveDocument* activeDocument;
    Block* previousActiveBlock;
};