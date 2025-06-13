/**
 * @file ViewAllBlocksCommand.hpp
 * @author MK
 * @brief A command to view all blocks in the active document in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../CommandsCLI/ViewAllBlocksCommandCLI.hpp"
#include "../Block/BlockRegister.hpp"
#include "../Document/ActiveDocument.hpp"

/**
 * @brief A command to view all blocks in the active document in the text processor application.
 */
class ViewAllBlocksCommand : public Command {
public:
    ViewAllBlocksCommand() = delete;
    ViewAllBlocksCommand(ViewAllBlocksCommandCLI* cli, ActiveDocument* activeDocument, BlockRegister* blockRegister);
    ViewAllBlocksCommand(const ViewAllBlocksCommand& other) = delete;
    ViewAllBlocksCommand& operator=(const ViewAllBlocksCommand& other) = delete;
    ~ViewAllBlocksCommand() override = default;

    void execute() override;
    void undo() override {};
    string getName() const override;
    bool isUndoable() const override;

    private:
    ViewAllBlocksCommandCLI* cli;
    ActiveDocument* activeDocument;
    BlockRegister* blockRegister;
};