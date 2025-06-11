#include "../../headers/Commands/SortCommand.hpp"

SortCommand::SortCommand(SortCommandCLI* cli, ActiveDocument* activeDocument, ActiveBlock* activeBlock) {
    this->cli = cli;
    this->activeDocument = activeDocument;
    this->activeBlock = activeBlock;
    this->previousDocument = nullptr;
}

string SortCommand::getName() const {
    return "Sort";
}

SortCommand::~SortCommand() {
    delete previousDocument;
}

void SortCommand::execute() {

    if(!activeDocument->getActiveDocument()) {
        cli->error("Please set an active document before sorting.");
        return;
    }

    previousDocument = new Document(*activeDocument->getActiveDocument());

    if(activeBlock->getActiveBlock()) {
        activeDocument->getActiveDocument()->sort(activeBlock->getActiveBlock()->getStartLineIndex(), 
                                                        activeBlock->getActiveBlock()->getEndLineIndex());
    } else {
        activeDocument->getActiveDocument()->sort();
    }

    cli->success();
}


void SortCommand::undo() {

    if(!previousDocument) {
        cli->nothingToUndo();
        return;
    }

    if(!activeDocument->getActiveDocument()) {
        cli->error("Please set an active document before trying to undo sorting.");
        return;
    }

    if(*activeDocument->getActiveDocument() == *previousDocument) {
        cli->nothingToUndo();
        return;
    }

    *activeDocument->getActiveDocument() = *previousDocument;

    delete previousDocument;
    previousDocument = nullptr;
    cli->successUndo();
}