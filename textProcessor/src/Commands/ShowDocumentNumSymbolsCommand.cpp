#include "../../headers/Commands/ShowDocumentNumSymbolsCommand.hpp"

/**
 * @file ShowDocumentNumSymbolsCommand.cpp
 * @author MK
 * @brief A command to show the number of symbols in the active document.
 */


ShowDocumentNumSymbolsCommand::ShowDocumentNumSymbolsCommand(ShowDocumentNumSymbolsCommandCLI* cli, ActiveDocument* activeDocument) {
    this->cli = cli;
    this->activeDocument = activeDocument;
}


/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string ShowDocumentNumSymbolsCommand::getName() const {
    return SHOW_DOCUMENT_NUM_SYMBOLS_COMMAND_NAME;
}

/**
 * @brief Executes the command to show the number of symbols in the active document.
 * 
 * This method retrieves the active document and its number of symbols, then displays it using the CLI.
 */
void ShowDocumentNumSymbolsCommand::execute() {
    Document* activeDoc = activeDocument->getActiveDocument();
    if (!activeDoc) {
        cli->error(ERROR_NO_ACTIVE_DOCUMENT);
        return;
    }
    
    int numSymbols = activeDoc->getNumSymbols();
    cli->showNumSymbols(numSymbols);
}

/**
 * @brief Indicates whether the command is undoable.
 * 
 * @return bool Always returns false, as this command does not support undo functionality.
 */
bool ShowDocumentNumSymbolsCommand::isUndoable() const {
    return false;
}