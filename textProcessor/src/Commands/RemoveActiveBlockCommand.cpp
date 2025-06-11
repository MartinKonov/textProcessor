#include "../../headers/Commands/RemoveActiveBlockCommand.hpp"



RemoveActiveBlockCommand::RemoveActiveBlockCommand(RemoveActiveBlockCommandCLI* cli, ActiveBlock* activeBlock, ActiveDocument* activeDocument) {
    this->cli = cli;
    this->activeBlock = activeBlock;
    this->activeDocument = activeDocument;
    this->previousActiveBlock = nullptr;
}

RemoveActiveBlockCommand::~RemoveActiveBlockCommand() {
    delete previousActiveBlock;
}

string RemoveActiveBlockCommand::getName() const {
    return "Remove Active Block";
}

void RemoveActiveBlockCommand::execute() {
    if(!activeBlock->getActiveBlock()) {
        cli->error("There is no active block to remove.");
        return;
    }

    if(activeBlock->getActiveBlock()){
        previousActiveBlock = new Block(*activeBlock->getActiveBlock());
    }

    activeBlock->removeActiveBlock();

    cli->success();
}

void RemoveActiveBlockCommand::undo() {
    if(!previousActiveBlock) {
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
