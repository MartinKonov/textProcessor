#include "../../headers/Commands/RemoveRepeatsCommand.hpp"

/**
 * @file RemoveRepeatsCommand.cpp
 * @author MK
 * @brief A command to remove repeated lines in the active document or block in the text processor application.
 */
RemoveRepeatsCommand::RemoveRepeatsCommand(RemoveRepeatsCommandCLI* cli, ActiveDocument* activeDocument, ActiveBlock* activeBlock) {
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
string RemoveRepeatsCommand::getName() const {
    return REMOVE_REPEATS_COMMAND_NAME;
}
/**
 * @brief Destructor for RemoveRepeatsCommand.
 * It deletes the previous document to free up memory.
 */
RemoveRepeatsCommand::~RemoveRepeatsCommand() {
    delete previousDocument;
    previousDocument = nullptr;
}

/**
 * @brief Executes the command to remove repeated lines in the active document or block.
 * 
 * This method checks if there is an active document. If there is, it saves the current state of the document
 * for potential undo functionality and then removes repeated lines in the active block or the entire document.
 */
void RemoveRepeatsCommand::execute() {

    if(!activeDocument->getActiveDocument()) {
        cli->error(ERROR_NO_ACTIVE_DOCUMENT);
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    if(previousDocument) {
        delete previousDocument;
        previousDocument = nullptr;
    }
    previousDocument = new Document(*activeDocument->getActiveDocument());

    if(activeBlock->getActiveBlock()) {
        activeDocument->getActiveDocument()->removeRepeats(activeBlock->getActiveBlock()->getStartLineIndex(),
                                                           activeBlock->getActiveBlock()->getEndLineIndex());
    } else {
        activeDocument->getActiveDocument()->removeRepeats();
    }
    
    cli->success();
}

/**
 * @brief Undoes the last executed command of removing repeated lines.
 * 
 * This method restores the previous state of the document before the removal of repeated lines.
 */
void RemoveRepeatsCommand::undo() {
    if(!previousDocument) {
        cli->error(ERROR_UNDO);
        return;
    }

    Document* doc = activeDocument->getActiveDocument();
    if(!doc) {
        cli->error(ERROR_NO_ACTIVE_DOCUMENT);
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    if(*doc == *previousDocument) {
        cli->error(ERROR_UNDO);
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    if(doc->getDocName() != previousDocument->getDocName()) {
        cli->error(ERROR_ACTIVE_DOCUMENT_CHANGED);
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    *doc = *previousDocument;
    cli->successUndo();
    delete previousDocument;
    previousDocument = nullptr;
}