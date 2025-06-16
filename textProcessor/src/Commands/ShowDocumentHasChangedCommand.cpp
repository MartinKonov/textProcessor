#include "../../headers/Commands/ShowDocumentHasChangedCommand.hpp"

/**
 * @file ShowDocumentHasChangedCommand.cpp
 * @author MK
 * @brief A command to show whether the active document has changed.
 */
ShowDocumentHasChangedCommand::ShowDocumentHasChangedCommand(ShowDocumentHasChangedCommandCLI* cli, ActiveDocument* activeDocument) {
    this->cli = cli;
    this->activeDocument = activeDocument;
}
/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string ShowDocumentHasChangedCommand::getName() const {
    return "Show ActiveDocument Has Changed";
}
/**
 * @brief Executes the command to show whether the active document has changed.
 * 
 * This method checks if there is an active document and then retrieves its changed status,
 * displaying it using the CLI.
 */
void ShowDocumentHasChangedCommand::execute() {
    Document* activeDoc = activeDocument->getActiveDocument();
    if (!activeDoc) {
        cli->error("No active document set.");
        return;
    }
    
    bool hasChanged = activeDoc->getHasChanged();
    cli->showDocumentHasChanged(hasChanged);
}

/**
 * @brief Indicates whether the command is undoable.
 * 
 * @return bool Always returns false, as this command does not support undo functionality.
 */
bool ShowDocumentHasChangedCommand::isUndoable() const {
    return false;
}