#include "../../headers/Commands/CreateBlockCommand.hpp"


/**
 * @file CreateBlockCommand.cpp
 * @author MK
 * @brief A command to create a block in the text processor application.
 */
CreateBlockCommand::CreateBlockCommand(CreateBlockCommandCLI* cli, BlockRegister* blockRegister, ActiveDocument* activeDocument) {
    this->activeDocument = activeDocument;
    this->cli = cli;
    this->blockRegister = blockRegister;
}

/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string CreateBlockCommand::getName() const {
    return CREATE_BLOCK_COMMAND_NAME;
}

/**
 * @brief Executes the command to create a block.
 * 
 * This method checks if there is an active document, retrieves the block name,
 * checks if the block already exists, and adds the block to the register.
 * If successful, it updates the name of the last created block.
 */
void CreateBlockCommand::execute() {

    if(!activeDocument->getActiveDocument()) {
        cli->error(ERROR_NO_ACTIVE_DOCUMENT);
        return;
    }

    string blockName = cli->getBlockName();

    if(blockRegister->itemExists(blockName)){
        cli->error(ERROR_BLOCK_ALREADY_EXISTS);
        return;
    }

    size_t startLineIndex = cli->getStartLineIndex();
    size_t endLineIndex = cli->getEndLineIndex();

    try{
        blockRegister->addBlock(blockName, activeDocument->getActiveDocument(), startLineIndex-1, endLineIndex-1);
    } catch(runtime_error& e) {
        cli->error(e.what());
        return;
    }
    nameOfLastBlockCreated = blockName;

    cli->success();
}

/**
 * @brief Undoes the last executed command of creating a block.
 * 
 * This method removes the last created block from the block register.
 * If there is an error during the removal, it shows an error message.
 */
void CreateBlockCommand::undo() {
    try{
        blockRegister->removeItem(nameOfLastBlockCreated);
    } catch(runtime_error& e) {
        cli->error(e.what());
    }
    cli->successUndo();
}