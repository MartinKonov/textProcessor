#include "../../headers/Commands/SetActiveBlockCommand.hpp"

/**
 * @file SetActiveBlockCommand.cpp
 * @author MK
 * @brief A command to set the active block in the text processor application.
 */
SetActiveBlockCommand::SetActiveBlockCommand(SetActiveBlockCommandCLI* setActiveBlockCommandCLI,ActiveBlock* activeBlock, ActiveDocument* activeDocument, BlockRegister* blockRegister) {
    this->setActiveBlockCommandCLI = setActiveBlockCommandCLI;
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
    return "Set Active Block";
}

/**
 * @brief Executes the command to set the active block.
 * 
 * This method retrieves all blocks for the active document, prompts the user to select a new active block,
 * and sets it as the active block. If there is a previous active block, it saves it for potential undo functionality.
 */
void SetActiveBlockCommand::execute() {
    
    if(!activeDocument->getActiveDocument()) {
        setActiveBlockCommandCLI->errorActiveDocument();
        return;
    }

    string blocksForDocSerialized = blockRegister->showAllForDocument(activeDocument->getActiveDocument()->getDocName());
    setActiveBlockCommandCLI->showBlocksForActiveDoc(blocksForDocSerialized);

    string newActiveBlockName = setActiveBlockCommandCLI->getNewActiveBlockName();

    if(activeBlock->getActiveBlock()){
        previousActiveBlock = new Block(*activeBlock->getActiveBlock());
    }

    try{
        activeBlock->setActiveBlock(newActiveBlockName, activeDocument->getActiveDocument());
    } catch (runtime_error& e) {
        setActiveBlockCommandCLI->error(e.what());
        return;
    }

    setActiveBlockCommandCLI->success();
}

/**
 * @brief Undoes the last executed command of setting the active block.
 * 
 * This method restores the previous active block if it exists and if the active document has not changed.
 * If the active document has changed, it shows an error message and does not perform the undo operation.
 */
void SetActiveBlockCommand::undo() {

    if(!previousActiveBlock){
        setActiveBlockCommandCLI->nothingToUndo();
        return;
    }

    if(activeDocument->getActiveDocument()->getDocName() != previousActiveBlock->getDocumentName()) {
        setActiveBlockCommandCLI->documentHasChanged();
        delete previousActiveBlock;
        previousActiveBlock = nullptr;
        return;
    }

    try {
        activeBlock->setActiveBlock(previousActiveBlock->getName(), activeDocument->getActiveDocument());
    } catch(runtime_error& e) {
        setActiveBlockCommandCLI->errorUndo(e.what());
    }

    delete previousActiveBlock;
    previousActiveBlock = nullptr;
}