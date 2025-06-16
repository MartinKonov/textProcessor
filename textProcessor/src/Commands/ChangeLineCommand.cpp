#include "../../headers/Commands/ChangeLineCommand.hpp"


/**
 * @file ChangeLineCommand.cpp
 * @author MK
 * @brief A command to change the content of a specific line in the active document.
 */
ChangeLineCommand::ChangeLineCommand(ChangeLineCommandCLI* cli, ActiveDocument* activeDocument) {
    this->cli = cli;
    this->activeDocument = activeDocument;
    this->previousDocument = nullptr;
}

/**
 * @brief Destructor for ChangeLineCommand.
 * It deletes the previous document to free up memory.
 */
ChangeLineCommand::~ChangeLineCommand() {
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
string ChangeLineCommand::getName() const {
    return CHANGE_LINE_COMMAND_NAME;
}
/**
 * @brief Executes the command to change a specific line in the active document.
 * 
 * This method retrieves the line number and new content from the CLI, checks if the active document is set,
 * and then changes the specified line in the document. If successful, it updates the previous document for potential undo functionality.
 */
void ChangeLineCommand::execute() {
    if (!activeDocument->getActiveDocument()) {
        cli->error("No active document set.");
        return;
    }
    cli->showDocumentWithIndices(activeDocument->getActiveDocument()->toString());
    int lineNumber;
    try{
        lineNumber = cli->getLineNumberToChange();
    }
    catch (const runtime_error& e) {
        cli->error(e.what());
        return;
    }
    string newContent = cli->getNewLineContent();

    if(previousDocument) {
        delete previousDocument;
        previousDocument = nullptr;
    }
    previousDocument = new Document(*activeDocument->getActiveDocument());

    try {
        activeDocument->getActiveDocument()->changeLine(lineNumber - 1, newContent);
    } catch (const runtime_error& e) {
        cli->error(e.what());
    }
    cli->success();
}


/**
 * @brief Undoes the last executed command of changing a line.
 * 
 * This method restores the previous document if it exists, allowing the user to revert the changes made by the execute method.
 */
void ChangeLineCommand::undo() {
    if (!previousDocument) {
        cli->error("No previous document to restore.");
        return;
    }

    if (!activeDocument->getActiveDocument()) {
        cli->error("No active document set.");
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    if(activeDocument->getActiveDocument()->getDocName() != previousDocument->getDocName()) {
        cli->error("The active document has changed since the last command.");
        delete previousDocument;
        previousDocument = nullptr;
        return;
    }

    *activeDocument->getActiveDocument() = *previousDocument;
    delete previousDocument;
    previousDocument = nullptr;

    cli->successUndo();
}