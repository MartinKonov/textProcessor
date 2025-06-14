#include "../../headers/Commands/SortCommand.hpp"

/**
 * @file SortCommand.cpp
 * @author MK
 * @brief A command to sort the lines in the active document or block in the text processor application.
 */
SortCommand::SortCommand(SortCommandCLI* cli, ActiveDocument* activeDocument, ActiveBlock* activeBlock) {
    this->cli = cli;
    this->activeDocument = activeDocument;
    this->activeBlock = activeBlock;
    this->previousDocument = nullptr;
}

/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string SortCommand::getName() const {
    return "Sort";
}

/**
 * @brief Destructor for SortCommand.
 * It deletes the previous document to free up memory.
 */
SortCommand::~SortCommand() {
    delete previousDocument;
}

/**
 * @brief Executes the command to sort the lines in the active document or block.
 * 
 * This method checks if there is an active document. If there is, it saves the current state of the document
 * for potential undo functionality and then sorts the lines in the active block or the entire document.
 */
void SortCommand::execute() {

    if(!activeDocument->getActiveDocument()) {
        cli->error("Please set an active document before sorting.");
        return;
    }

    if(previousDocument) {
        delete previousDocument;
        previousDocument = nullptr;
    }
    previousDocument = new Document(*activeDocument->getActiveDocument());

    if(*activeDocument->getActiveDocument() == *previousDocument) {
        cli->nothingToUndo();
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    if(previousDocument->getDocName() != activeDocument->getActiveDocument()->getDocName()) {
        cli->error("The active document has changed since the last sort command. Cannot proceed with sorting.");
        return;
    }

    if(activeBlock->getActiveBlock()) {
        activeDocument->getActiveDocument()->sort(activeBlock->getActiveBlock()->getStartLineIndex(), 
                                                        activeBlock->getActiveBlock()->getEndLineIndex());
    } else {
        activeDocument->getActiveDocument()->sort();
    }

    cli->success();
}

/**
 * @brief Undoes the last executed command of sorting.
 */
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