#include "../../headers/Commands/SetActiveDocumentCommand.hpp"

/**
 * @file SetActiveDocumentCommand.cpp
 * @author MK
 * @brief A command to set the active document in the text processor application.
 */
SetActiveDocumentCommand::SetActiveDocumentCommand(SetActiveDocumentCommandCLI* cli, ActiveDocument* activeDocument) {
    this->cli = cli;
    this->activeDocument = activeDocument;
}

/**
 * @brief gets the name of the command.
 * @return string The name of the command.
 */
string SetActiveDocumentCommand::getName() const {
    return SET_ACTIVE_DOCUMENT_COMMAND_NAME;
}

/**
 * @brief Executes the command to set the active document.
 * 
 * This method retrieves the document path from the CLI and attempts to set it as the active document.
 * If an error occurs during setting, it catches the exception and displays an error message.
 */
void SetActiveDocumentCommand::execute() {
    string docName = cli->getDocPath();

    try {
        if(activeDocument->getActiveDocument()) {
            previousActiveDocumentName = activeDocument->getActiveDocument()->getDocName();
        }
        activeDocument->setActiveDocument(docName);
    } catch (runtime_error& e) {
        cli->error(e.what());
        previousActiveDocumentName.clear();
        return;
    }
    
    cli->success();
}

/**
 * @brief Undoes the last executed command of setting the active document.
 * 
 * This method restores the previous active document if it exists. If the previous active document name is empty,
 * it shows an error message and does not perform the undo operation.
 */
void SetActiveDocumentCommand::undo() {
    if(previousActiveDocumentName.empty())
    {
        cli->error(ERROR_UNDO);
        return;
    }

    try {
        activeDocument->setActiveDocument(previousActiveDocumentName);
    } catch(runtime_error& e)
    {
        cli->error(e.what());
    }

}