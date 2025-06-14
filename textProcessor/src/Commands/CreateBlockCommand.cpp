#include "../../headers/Commands/CreateBlockCommand.hpp"


/**
 * @file CreateBlockCommand.cpp
 * @author MK
 * @brief A command to create a block in the text processor application.
 */
CreateBlockCommand::CreateBlockCommand(CreateBlockCommandCLI* createBlockCommandCLI, BlockRegister* blockRegister, ActiveDocument* activeDocument) {
    this->activeDocument = activeDocument;
    this->createBlockCommandCLI = createBlockCommandCLI;
    this->blockRegister = blockRegister;
}

/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string CreateBlockCommand::getName() const {
    return "Create Block";
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
        createBlockCommandCLI->errorNoActiveDocument();
        return;
    }

    string blockName = createBlockCommandCLI->getBlockName();

    if(blockRegister->itemExists(blockName)){
        createBlockCommandCLI->blockExists();
        return;
    }

    size_t startLineIndex = createBlockCommandCLI->getStartLineIndex();
    size_t endLineIndex = createBlockCommandCLI->getEndLineIndex();

    try{
        blockRegister->addBlock(blockName, activeDocument->getActiveDocument(), startLineIndex-1, endLineIndex-1);
    } catch(runtime_error& e) {
        createBlockCommandCLI->error(e.what());
        return;
    }
    nameOfLastBlockCreated = blockName;

    createBlockCommandCLI->success();
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
        createBlockCommandCLI->error(e.what());
    }
    createBlockCommandCLI->successUndo();
}