#include "../../headers/Commands/SetActiveBlockCommand.hpp"

/**
 * @file SetActiveBlockCommand.cpp
 * @author MK
 * @brief A command to set the active block in the text processor application.
 */
SetActiveBlockCommand::SetActiveBlockCommand(SetActiveBlockCommandCLI* cli,ActiveBlock* activeBlock, ActiveDocument* activeDocument, BlockRegister* blockRegister) {
    this->cli = cli;
    this->activeBlock = activeBlock;
    this->activeDocument = activeDocument;
    this->blockRegister = blockRegister;
    this->previousActiveBlock = nullptr;
}

/**
 * @brief Destructor for SetActiveBlockCommand.
 * It deletes the previous active block to free up memory.
 */
SetActiveBlockCommand::~SetActiveBlockCommand() {
    delete previousActiveBlock;
}

/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string SetActiveBlockCommand::getName() const {
    return SET_ACTIVE_BLOCK_COMMAND_NAME;
}

/**
 * @brief Executes the command to set the active block.
 * 
 * This method retrieves all blocks for the active document, prompts the user to select a new active block,
 * and sets it as the active block. If there is a previous active block, it saves it for potential undo functionality.
 */
void SetActiveBlockCommand::execute() {
    
    if(!activeDocument->getActiveDocument()) {
        cli->errorActiveDocument();
        return;
    }

    string blocksForDocSerialized = blockRegister->showAllForDocument(activeDocument->getActiveDocument()->getDocName());
    cli->showBlocksForActiveDoc(blocksForDocSerialized);

    string newActiveBlockName = cli->getNewActiveBlockName();

    if(activeBlock->getActiveBlock()){
        previousActiveBlock = new Block(*activeBlock->getActiveBlock());
    }

    try{
        activeBlock->setActiveBlock(newActiveBlockName, activeDocument->getActiveDocument());
    } catch (runtime_error& e) {
        cli->error(e.what());
        return;
    }

    cli->success();
}

/**
 * @brief Undoes the last executed command of setting the active block.
 * 
 * This method restores the previous active block if it exists and if the active document has not changed.
 * If the active document has changed, it shows an error message and does not perform the undo operation.
 */
void SetActiveBlockCommand::undo() {

    if(!previousActiveBlock){
        cli->nothingToUndo();
        return;
    }

    if(activeDocument->getActiveDocument()->getDocName() != previousActiveBlock->getDocumentName()) {
        cli->documentHasChanged();
        delete previousActiveBlock;
        previousActiveBlock = nullptr;
        return;
    }

    try {
        activeBlock->setActiveBlock(previousActiveBlock->getName(), activeDocument->getActiveDocument());
    } catch(runtime_error& e) {
        cli->errorUndo(e.what());
    }

    delete previousActiveBlock;
    previousActiveBlock = nullptr;
}