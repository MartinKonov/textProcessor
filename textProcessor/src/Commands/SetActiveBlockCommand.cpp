#include "../../headers/Commands/SetActiveBlockCommand.hpp"


SetActiveBlockCommand::SetActiveBlockCommand(SetActiveBlockCommandCLI* setActiveBlockCommandCLI,ActiveBlock* activeBlock, ActiveDocument* activeDocument, BlockRegister* blockRegister) {
    this->setActiveBlockCommandCLI = setActiveBlockCommandCLI;
    this->activeBlock = activeBlock;
    this->activeDocument = activeDocument;
    this->blockRegister = blockRegister;
    this->previousActiveBlock = nullptr;
}

SetActiveBlockCommand::~SetActiveBlockCommand() {
    delete previousActiveBlock;
}

string SetActiveBlockCommand::getName() const {
    return "Set Active Block";
}

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