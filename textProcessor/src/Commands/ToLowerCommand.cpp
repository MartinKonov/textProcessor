#include "../../headers/Commands/ToLowerCommand.hpp"


/**
 * @file ToLowerCommand.cpp
 * @author MK
 * @brief A command to convert the content of the active document to lowercase.
 */
ToLowerCommand::ToLowerCommand(ToLowerCommandCLI* cli, ActiveDocument* activeDocument, ActiveBlock* activeBlock) {
    this->cli = cli;
    this->activeDocument = activeDocument;
    this->previousDocumentState = nullptr;
    this->activeBlock = activeBlock;
}

ToLowerCommand::~ToLowerCommand() {
    delete previousDocumentState;
    previousDocumentState = nullptr;
}

/**
 * @brief Returns the name of the command.
 * 
 * This method provides the name of the command, which is used for display purposes in the CLI.
 * 
 * @return string The name of the command.
 */
string ToLowerCommand::getName() const {
    return TO_LOWER_COMMAND_NAME;
}


/**
 * @brief Executes the command to convert the content of the active document to lowercase.
 * 
 * This method checks if there is an active document, saves the previous document state for potential undo functionality,
 * and converts the content of the active block or the entire document to lowercase.
 */
void ToLowerCommand::execute() {
    Document* activeDoc = activeDocument->getActiveDocument();
    if (!activeDoc) {
        cli->error(ERROR_NO_ACTIVE_DOCUMENT);
        return;
    }

    if(previousDocumentState) {
        delete previousDocumentState;
        previousDocumentState = nullptr;
    }

    previousDocumentState = new Document(*activeDoc);

    if(activeBlock->getActiveBlock()) {
        activeDoc->toLower(activeBlock->getActiveBlock()->getStartLineIndex(), 
                           activeBlock->getActiveBlock()->getEndLineIndex());
    } else {
        activeDoc->toLower();
    }
    
    cli->success();
}

/**
 * @brief Undoes the last executed command of converting the content to lowercase.
 * 
 * This method restores the previous document state if it exists and if the active document has not changed.
 * If the active document has changed, it shows an error message and does not perform the undo operation.
 */
void ToLowerCommand::undo() {
    if (!previousDocumentState) {
        cli->error(ERROR_UNDO);
        return;
    }

    Document* activeDoc = activeDocument->getActiveDocument();
    if (!activeDoc) {
        cli->error(ERROR_NO_ACTIVE_DOCUMENT);
        delete previousDocumentState;
        previousDocumentState = nullptr;
        return;
    }

    if(*activeDoc == *previousDocumentState) {
        cli->error(ERROR_UNDO);
        delete previousDocumentState;
        previousDocumentState = nullptr;
        return;
    }

    if (activeDoc->getDocName() != previousDocumentState->getDocName()) {
        delete previousDocumentState;
        previousDocumentState = nullptr;
        cli->error(ERROR_ACTIVE_DOCUMENT_CHANGED);
        return;
    }

    *activeDoc = *previousDocumentState;
    delete previousDocumentState;
    previousDocumentState = nullptr;
    cli->successUndo();
}