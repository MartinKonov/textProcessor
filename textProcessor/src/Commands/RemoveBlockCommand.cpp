#include "../../headers/Commands/RemoveBlockCommand.hpp"


RemoveBlockCommand::RemoveBlockCommand(RemoveBlockCommandCLI* removeBlockCommandCLI, BlockRegister* blockRegister, DocumentRegister* documentRegister) {
    this->removeBlockCommandCLI = removeBlockCommandCLI;
    this->blockRegister = blockRegister;
    this->documentRegister = documentRegister;
    this->removedBlock = nullptr;
}

RemoveBlockCommand::~RemoveBlockCommand() {
    delete removedBlock;
}

string RemoveBlockCommand::getName() const {
    return "Remove Block";
}

void RemoveBlockCommand::execute() {

    string blockName = removeBlockCommandCLI->getBlockName();

    if(!blockRegister->itemExists(blockName)) {
        removeBlockCommandCLI->blockDoesntExist();
        return;
    }

    this->removedBlock = new Block(*blockRegister->getItem(blockName));
    try {
        blockRegister->removeItem(blockName);
    } catch (runtime_error& e) {
        removeBlockCommandCLI->error(e.what());
    }


    removeBlockCommandCLI->success();
}

void RemoveBlockCommand::undo() {
    if(!removedBlock) {
        removeBlockCommandCLI->removedBlockError();
        return;
    }

    try{
        Document* documentOfRemovedBlock = documentRegister->getDocument(removedBlock->getDocumentName());
        blockRegister->addBlock(removedBlock->getName(), documentOfRemovedBlock, removedBlock->getStartLineIndex(), removedBlock->getEndLineIndex());

    } catch (runtime_error& e)
    {
        removeBlockCommandCLI->errorUndo(e.what());
    }
    delete removedBlock;
    removedBlock = nullptr;
}
