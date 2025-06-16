#include "../../headers/Commands/ShowDocumentNameCommand.hpp"


/**
 * @file ShowDocumentName.cpp
 * @author MK
 * @brief A command to show the name of the active document in the text processor application.
 */
ShowDocumentNameCommand::ShowDocumentNameCommand(ShowDocumentNameCommandCLI* cli, ActiveDocument* activeDocument) {
    this->cli = cli;
    this->activeDocument = activeDocument;
}

/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string ShowDocumentNameCommand::getName() const {
    return SHOW_DOCUMENT_NAME_COMMAND_NAME;
}

/**
 * @brief Executes the command to show the name of the active document.
 * 
 * This method retrieves the name of the active document and displays it using the CLI.
 */
void ShowDocumentNameCommand::execute() {
    Document* activeDoc = activeDocument->getActiveDocument();
    if (activeDoc) {
        cli->showDocumentName(activeDoc->getDocName());
    } else {
        cli->error(ERROR_NO_ACTIVE_DOCUMENT);
    }
}

/**
 * @brief Undoes the command.
 * 
 * This command is not undoable, so this method does nothing.
 */
void ShowDocumentNameCommand::undo() {
}
/**
 * @brief Show document name command is not undoable.
 */
bool ShowDocumentNameCommand::isUndoable() const {
    return false;
}