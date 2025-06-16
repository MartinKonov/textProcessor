#include "../../headers/Commands/ShowDocumentNumLinesCommand.hpp"

/**
 * @file ShowDocumentNumLinesCommand.cpp
 * @author MK
 * @brief A command to show the number of lines in the active document in the text processor application.
 */
ShowDocumentNumLinesCommand::ShowDocumentNumLinesCommand(ShowDocumentNumLinesCommandCLI* cli, ActiveDocument* activeDocument) {
    this->cli = cli;
    this->activeDocument = activeDocument;
}

/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string ShowDocumentNumLinesCommand::getName() const {
    return SHOW_DOCUMENT_NUM_LINES_COMMAND_NAME;
}


/**
 * @brief Executes the command to show the number of lines in the active document.
 * 
 * This method retrieves the active document and displays the number of lines using the CLI.
 */
void ShowDocumentNumLinesCommand::execute() {
    Document* activeDoc = activeDocument->getActiveDocument();
    if (activeDoc) {
        int numLines = activeDoc->getNumLines();
        cli->showNumLines(numLines);
    } else {
        cli->error("No active document set.");
    }
}

/**
 * @brief Command does not have an undo operation.
 */
bool ShowDocumentNumLinesCommand::isUndoable() const {
    return false;
}