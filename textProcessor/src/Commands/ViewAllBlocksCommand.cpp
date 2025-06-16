/**
 * @file ViewAllBlocksCommand.cpp
 * @author MK
 * @brief A command to view all blocks in the active document in the text processor application.
 */
#include "../../headers/Commands/ViewAllBlocksCommand.hpp"



ViewAllBlocksCommand::ViewAllBlocksCommand(ViewAllBlocksCommandCLI* cli, ActiveDocument* activeDocument, BlockRegister* blockRegister) {
    this->cli = cli;
    this->activeDocument = activeDocument;
    this->blockRegister = blockRegister;
}

/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string ViewAllBlocksCommand::getName() const {
    return VIEW_ALL_BLOCKS_COMMAND_NAME;
}

/**
 * @brief Executes the command to view all blocks in the active document.
 * 
 * This method retrieves all blocks for the active document and displays them using the CLI.
 * If there are no blocks found, it shows an error message.
 */
void ViewAllBlocksCommand::execute() {
    if (!activeDocument->getActiveDocument()) {
        cli->error("Please set an active document before viewing blocks.");
        return;
    }

    string blocksForDocSerialized = blockRegister->showAllForDocument(activeDocument->getActiveDocument()->getDocName());
    if (blocksForDocSerialized.empty()) {
        cli->error("No blocks found for the active document.");
        return;
    }

    cli->success();
    cli->showBlocksForActiveDoc(blocksForDocSerialized);
}

/**
 * @brief This command is not undoable.
 */
bool ViewAllBlocksCommand::isUndoable() const {
    return false;
}