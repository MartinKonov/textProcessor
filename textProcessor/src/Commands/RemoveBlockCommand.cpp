#include "../../headers/Commands/RemoveBlockCommand.hpp"


/**
 * @file RemoveBlockCommand.cpp
 * @author MK
 * @brief A command to remove a block in the text processor application.
 */
RemoveBlockCommand::RemoveBlockCommand(RemoveBlockCommandCLI* cli, BlockRegister* blockRegister, DocumentRegister* documentRegister) {
    this->cli = cli;
    this->blockRegister = blockRegister;
    this->documentRegister = documentRegister;
    this->removedBlock = nullptr;
}

/**
 * @brief Destructor for RemoveBlockCommand.
 * It deletes the removed block to free up memory.
 */
RemoveBlockCommand::~RemoveBlockCommand() {
    delete removedBlock;
    removedBlock = nullptr;
}

/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string RemoveBlockCommand::getName() const {
    return REMOVE_BLOCK_COMMAND_NAME;
}

/**
 * @brief Executes the command to remove a block.
 * 
 * This method checks if the block exists in the register, and if it does,
 * it removes the block and stores it for potential undo functionality.
 */
void RemoveBlockCommand::execute() {

    string blockName = cli->getBlockName();

    if(!blockRegister->itemExists(blockName)) {
        cli->error(ERROR_BLOCK_NOT_FOUND);
        return;
    }

    this->removedBlock = new Block(*blockRegister->getItem(blockName));
    try {
        blockRegister->removeItem(blockName);
    } catch (runtime_error& e) {
        cli->error(e.what());
    }


    cli->success();
}

/**
 * @brief Undoes the last executed command of removing a block.
 * 
 * This method restores the removed block to the block register if it exists.
 * If the removed block is null, it shows an error message.
 */
void RemoveBlockCommand::undo() {
    if(!removedBlock) {
        cli->error(ERROR_UNDO);
        return;
    }

    try{
        Document* documentOfRemovedBlock = documentRegister->getDocument(removedBlock->getDocumentName());
        blockRegister->addBlock(removedBlock->getName(), documentOfRemovedBlock, removedBlock->getStartLineIndex(), removedBlock->getEndLineIndex());

    } catch (runtime_error& e)
    {
        cli->error(e.what());
    }
    delete removedBlock;
    removedBlock = nullptr;
}
