#include "../../headers/Commands/RemoveActiveBlockCommand.hpp"


/**
 * @file RemoveActiveBlockCommand.cpp
 * @author MK
 * @brief A command to remove the active block in the text processor application.
 */
RemoveActiveBlockCommand::RemoveActiveBlockCommand(RemoveActiveBlockCommandCLI* cli, ActiveBlock* activeBlock, ActiveDocument* activeDocument) {
    this->cli = cli;
    this->activeBlock = activeBlock;
    this->activeDocument = activeDocument;
    this->previousActiveBlock = nullptr;
}

/**
 * @brief Destructor for RemoveActiveBlockCommand.
 * It deletes the previous active block to free up memory.
 */
RemoveActiveBlockCommand::~RemoveActiveBlockCommand() {
    delete previousActiveBlock;
}

/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string RemoveActiveBlockCommand::getName() const {
    return REMOVE_ACTIVE_BLOCK_COMMAND_NAME;
}

/**
 * @brief Executes the command to remove the active block.
 * 
 * This method checks if there is an active block to remove. If there is, it saves the previous active block
 * for potential undo functionality and then removes the active block.
 */
void RemoveActiveBlockCommand::execute() {
    if(!activeBlock->getActiveBlock()) {
        cli->error(ERROR_NO_ACTIVE_BLOCK);
        return;
    }

    if(activeBlock->getActiveBlock()){
        previousActiveBlock = new Block(*activeBlock->getActiveBlock());
    }

    activeBlock->removeActiveBlock();

    cli->success();
}

/**
 * @brief Undoes the last executed command of removing the active block.
 * 
 * This method restores the previous active block if it exists and if the active document has not changed.
 * If the active document has changed, it shows an error message and does not perform the undo operation.
 */
void RemoveActiveBlockCommand::undo() {
    if(!previousActiveBlock) {
        cli->error(ERROR_UNDO);
        return;
    }

    if(*activeBlock->getActiveBlock() == *previousActiveBlock) {
        cli->error(ERROR_UNDO);
        delete previousActiveBlock;
        previousActiveBlock = nullptr;
        return;
    }

    if(activeDocument->getActiveDocument()->getDocName() != previousActiveBlock->getDocumentName()) {
        cli->error(ERROR_ACTIVE_DOCUMENT_CHANGED);
        delete previousActiveBlock;
        previousActiveBlock = nullptr;
        return;
    }

    try {
        activeBlock->setActiveBlock(previousActiveBlock->getName(), activeDocument->getActiveDocument());
    } catch(runtime_error& e) {
        cli->error(e.what());
    }

    delete previousActiveBlock;
    previousActiveBlock = nullptr;
}
