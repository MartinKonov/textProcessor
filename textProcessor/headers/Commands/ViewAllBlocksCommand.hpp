#pragma once
#include "Command.hpp"
#include "../CommandsCLI/ViewAllBlocksCommandCLI.hpp"
#include "../Block/BlockRegister.hpp"
#include "../Document/ActiveDocument.hpp"


class ViewAllBlocksCommand : public Command {
public:
    ViewAllBlocksCommand() = delete;
    ViewAllBlocksCommand(ViewAllBlocksCommandCLI* cli, ActiveDocument* activeDocument, BlockRegister* blockRegister);
    ViewAllBlocksCommand(const ViewAllBlocksCommand& other) = delete;
    ViewAllBlocksCommand& operator=(const ViewAllBlocksCommand& other) = delete;
    ~ViewAllBlocksCommand() override = default;

    void execute() override;
    void undo() override;
    string getName() const override;

    private:
    ViewAllBlocksCommandCLI* cli;
    ActiveDocument* activeDocument;
    BlockRegister* blockRegister;
};