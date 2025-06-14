#include "../../headers/Commands/ToUpperCommand.hpp"


/**
 * @file ToUpperCommand.cpp
 * @author MK
 * @brief A command to convert the content of the active document or block to uppercase in the text processor application.
 */
ToUpperCommand::ToUpperCommand(ToUpperCommandCLI* cli, ActiveDocument* activeDocument, ActiveBlock* activeBlock) {
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
string ToUpperCommand::getName() const {
    return "To Upper";
}

/**
 * @brief Destructor for ToUpperCommand.
 * It deletes the previous document to free up memory.
 */
ToUpperCommand::~ToUpperCommand() {
    delete previousDocument;
    previousDocument = nullptr;
}

/**
 * @brief Executes the command to convert the content of the active document or block to uppercase.
 * 
 * This method checks if there is an active document. If there is, it saves the current state of the document
 * for potential undo functionality and then converts the content of the active block or the entire document to uppercase.
 */
void ToUpperCommand::execute() {

    if(!activeDocument->getActiveDocument()) {
        cli->error("No active document. Cannot convert to uppercase.");
        return;
    }

    if(previousDocument) {
        delete previousDocument;
        previousDocument = nullptr;
    }
    
    previousDocument = new Document(*activeDocument->getActiveDocument());

    if(activeBlock->getActiveBlock()) {
        activeDocument->getActiveDocument()->toUpper(activeBlock->getActiveBlock()->getStartLineIndex(), 
                                                     activeBlock->getActiveBlock()->getEndLineIndex());
    } else {
        activeDocument->getActiveDocument()->toUpper();
    }

    cli->success();
}

/**
 * @brief Undoes the last executed command of converting to uppercase.
 * 
 * This method restores the previous state of the document before the conversion.
 */
void ToUpperCommand::undo() {
    if(!previousDocument) {
        cli->nothingToUndo();
        return;
    }

    Document* currentDocument = activeDocument->getActiveDocument();
    if(!currentDocument) {
        cli->error("No active document set.");
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    if(currentDocument->getDocName() != previousDocument->getDocName()) {
        cli->error("Cannot undo: active document has changed.");
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    *currentDocument = *previousDocument;
    delete previousDocument;
    previousDocument = nullptr;
    cli->successUndo();
}