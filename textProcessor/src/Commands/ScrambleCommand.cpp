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
/**
 * @brief Returns the name of the command.
 * 
 * This method provides the name of the command, which is used for display purposes in the CLI.
 * 
 * @return string The name of the command.
 */
string ScrambleCommand::getName() const {
    return "Scramble";
}

/**
 * @brief Executes the command to scramble the active document.
 * 
 * This method scrambles the contents of the active document and updates the active block with the scrambled content.
 * It also saves the previous document state for potential undo functionality.
 */
void ScrambleCommand::execute() {
    if (!activeDocument->getActiveDocument()) {
        cli->errorActiveDocument();
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    if (previousDocument) {
        delete previousDocument;
        previousDocument = nullptr;
    }
    previousDocument = new Document(*activeDocument->getActiveDocument());

    if(previousDocument->getDocName() != activeDocument->getActiveDocument()->getDocName()) {
        cli->error("The active document has changed since the last scramble command. Cannot proceed with scrambling.");
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

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
        cli->nothingToUndo();
        return;
    }

    Document* currentDocument = activeDocument->getActiveDocument();
    if (!currentDocument) {
        cli->error("No active document to undo the scramble operation.");
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    if (*currentDocument == *previousDocument) {
        cli->nothingToUndo();
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    if (currentDocument->getDocName() != previousDocument->getDocName()) {
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
