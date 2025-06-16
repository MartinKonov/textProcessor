#include "../../headers/Commands/TrimLeadingCommand.hpp"

/**
 * @file TrimLeadingCommand.cpp
 * @author MK
 * @brief A command to trim leading whitespace from the active block in the active document or the whole active document.
 */
TrimLeadingCommand::TrimLeadingCommand(TrimLeadingCommandCLI* cli, ActiveDocument* activeDocument, ActiveBlock* activeBlock) {
    this->cli = cli;
    this->activeDocument = activeDocument;
    this->activeBlock = activeBlock;
    this->previousDocument = nullptr;
}

/**
 * @brief Destructor for TrimLeadingCommand.
 * It deletes the previous document to free up memory.
 */
TrimLeadingCommand::~TrimLeadingCommand() {
    delete previousDocument;
    previousDocument = nullptr;
}

/**
 * @brief Returns the name of the command.
 * 
 * This method provides the name of the command, which is used for display purposes in the CLI.
 * 
 * @return string The name of the command.
 */
string TrimLeadingCommand::getName() const {
    return TRIM_LEADING_COMMAND_NAME;
}

/**
 * @brief Executes the command to trim leading whitespace.
 * 
 * This method checks if an active document is set. If not, it informs the user.
 * If an active block is set, it trims leading whitespace from the active block.
 * If no active block is set, it trims leading whitespace from the entire active document.
 */
void TrimLeadingCommand::execute() {
    
    if(previousDocument) {
        delete previousDocument;
        previousDocument = nullptr;
    }
    
    if (!activeDocument->getActiveDocument()) {
        cli->error(ERROR_NO_ACTIVE_DOCUMENT);
        return;
    }

    previousDocument = new Document(*activeDocument->getActiveDocument());

    if (activeBlock->getActiveBlock()) {
        activeDocument->getActiveDocument()->trimLeading(activeBlock->getActiveBlock()->getStartLineIndex(),
                                                         activeBlock->getActiveBlock()->getEndLineIndex());
    } else {
        activeDocument->getActiveDocument()->trimLeading();
    }

    cli->success();
}

/**
 * @brief Undoes the last executed command of trimming leading whitespace.
 * 
 * This method restores the previous state of the document before the trim operation.
 */
void TrimLeadingCommand::undo() {
    if (!previousDocument) {
        cli->error(ERROR_UNDO);
        return;
    }

    Document* currentDocument = activeDocument->getActiveDocument();
    if (!currentDocument) {
        cli->error(ERROR_NO_ACTIVE_DOCUMENT);
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    if(*currentDocument == *previousDocument) {
        cli->error(ERROR_UNDO);
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    if(currentDocument->getDocName() != previousDocument->getDocName()) {
        cli->error(ERROR_ACTIVE_DOCUMENT_CHANGED);
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    *activeDocument->getActiveDocument() = *previousDocument;
    delete previousDocument;
    previousDocument = nullptr;
    cli->successUndo();
}