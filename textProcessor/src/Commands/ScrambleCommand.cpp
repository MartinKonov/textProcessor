#include "../../headers/Commands/ScrambleCommand.hpp"


/**
 * @file ScrambleCommand.cpp
 * @author MK
 * @brief A command to scramble the contents of the active document in the text processor application.
 */
ScrambleCommand::ScrambleCommand(ScrambleCommandCLI* cli, ActiveDocument* activeDocument, ActiveBlock* activeBlock) {
    this->cli = cli;
    this->activeDocument = activeDocument;
    this->activeBlock = activeBlock;
    this->previousDocument = nullptr;
}

ScrambleCommand::~ScrambleCommand() {
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
string ScrambleCommand::getName() const {
    return SCRAMBLE_COMMAND_NAME;
}

/**
 * @brief Executes the command to scramble the active document.
 * 
 * This method scrambles the contents of the active document and updates the active block with the scrambled content.
 * It also saves the previous document state for potential undo functionality.
 */
void ScrambleCommand::execute() {
    if (!activeDocument->getActiveDocument()) {
        cli->error(ERROR_NO_ACTIVE_DOCUMENT);
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    if (previousDocument) {
        delete previousDocument;
        previousDocument = nullptr;
    }
    previousDocument = new Document(*activeDocument->getActiveDocument());

    if(activeBlock->getActiveBlock()) {
        activeDocument->getActiveDocument()->scramble(activeBlock->getActiveBlock()->getStartLineIndex(),
                                                      activeBlock->getActiveBlock()->getEndLineIndex());
    } else {
        activeDocument->getActiveDocument()->scramble();
    }

    cli->success();
}

/**
 * @brief Undoes the last executed command of scrambling the active document.
 * 
 * This method restores the previous state of the document before the scramble operation.
 */
void ScrambleCommand::undo() {
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

    if (*currentDocument == *previousDocument) {
        cli->error(ERROR_UNDO);
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    if (currentDocument->getDocName() != previousDocument->getDocName()) {
        cli->error(ERROR_ACTIVE_DOCUMENT_CHANGED);
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    *currentDocument = *previousDocument;
    delete previousDocument;
    previousDocument = nullptr;
    cli->successUndo();
}
