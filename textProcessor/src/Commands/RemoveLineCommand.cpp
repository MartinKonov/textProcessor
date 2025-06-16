#include "../../headers/Commands/RemoveLineCommand.hpp"

/**
 * @file RemoveLineCommand.cpp
 * @author MK
 * @brief A command to remove a line from the active document in the text processor application.
 */

RemoveLineCommand::RemoveLineCommand(RemoveLineCommandCLI* cli, ActiveDocument* activeDocument) {
    this->cli = cli;
    this->activeDocument = activeDocument;
    this->previousDocument = nullptr;
}

/**
 * @brief Destroys the previous document object.
 */
RemoveLineCommand::~RemoveLineCommand() {
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
string RemoveLineCommand::getName() const {
    return REMOVE_LINE_COMMAND_NAME;
}

/**
 * @brief Executes the command to remove a line from the active document.
 * 
 * This method retrieves the active document, prompts the user for the line number to remove,
 * checks if the line number is valid, and removes the specified line from the document.
 * It also saves the previous state of the document for potential undo operations.
 */
void RemoveLineCommand::execute() {
    Document* doc = activeDocument->getActiveDocument();
    if (!doc) {
        cli->error(ERROR_NO_ACTIVE_DOCUMENT);
        return;
    }

    cli->showDocumentWithIndices(doc->toString());
    string lineNumberStr = cli->getLineNumberToRemove();
    int lineNumber;
    try {
        lineNumber = stoi(lineNumberStr);
    } catch (const invalid_argument&) {
        cli->error(ERROR_INVALID_LINE_NUMBER);
        return;
    }

    if (lineNumber < 1 || lineNumber > doc->getNumLines()) {
        cli->error(ERROR_INDEX_OUT_OF_RANGE);
        return;
    }

    if(previousDocument) {
        delete previousDocument;
        previousDocument = nullptr;
    }
    previousDocument = new Document(*doc);
    doc->removeLine(lineNumber - 1);
    cli->success();
}

/**
 * @brief Undoes the last executed command of removing a line.
 */
void RemoveLineCommand::undo() {
    if (!previousDocument) {
        cli->error(ERROR_UNDO);
        return;
    }

    Document* doc = activeDocument->getActiveDocument();
    if (!doc) {
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

    if( doc->getDocName() != previousDocument->getDocName()) {
        cli->error(ERROR_ACTIVE_DOCUMENT_CHANGED);
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    *doc = *previousDocument;
    delete previousDocument;
    previousDocument = nullptr;
    cli->successUndo();
}