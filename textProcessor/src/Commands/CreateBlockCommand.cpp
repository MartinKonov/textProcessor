#include "../../headers/Commands/CreateBlockCommand.hpp"



CreateBlockCommand::CreateBlockCommand(CreateBlockCommandCLI* createBlockCommandCLI, BlockRegister* blockRegister, ActiveDocument* activeDocument) {
    this->activeDocument = activeDocument;
    this->createBlockCommandCLI = createBlockCommandCLI;
    this->blockRegister = blockRegister;
}

string CreateBlockCommand::getName() const {
    return "Create Block";
}

void CreateBlockCommand::execute() {

    if(!activeDocument->getActiveDocument()) {
        createBlockCommandCLI->errorNoActiveDocument();
    }

    string blockName = createBlockCommandCLI->getBlockName();

    if(blockRegister->itemExists(blockName)){
        createBlockCommandCLI->blockExists();
        return;
    }

    size_t startLineIndex = createBlockCommandCLI->getStartLineIndex();
    size_t endLineIndex = createBlockCommandCLI->getEndLineIndex();

    try{
        blockRegister->addBlock(blockName, activeDocument->getActiveDocument(), startLineIndex, endLineIndex);
    } catch(runtime_error& e) {
        createBlockCommandCLI->error(e.what());
    }
    nameOfLastBlockCreated = blockName;

    createBlockCommandCLI->success();
}

void CreateBlockCommand::undo() {
    try{
        blockRegister->removeItem(nameOfLastBlockCreated);
    } catch(runtime_error& e) {
        createBlockCommandCLI->error(e.what());
    }
    createBlockCommandCLI->successUndo();
}