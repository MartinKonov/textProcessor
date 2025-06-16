#include "../../headers/Commands/ListLoadedDocumentsCommand.hpp"


/**
 * @file ListLoadedDocumentsCommand.cpp
 * @author MK
 * @brief A command to list all loaded documents in the text processor application.
 */
ListLoadedDocumentsCommand::ListLoadedDocumentsCommand(ListLoadedDocumentsCommandCLI* cli, DocumentRegister* documentRegister) {
    this->cli = cli;
    this->documentRegister = documentRegister;
}

/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string ListLoadedDocumentsCommand::getName() const {
    return LIST_LOADED_DOCUMENTS_COMMAND_NAME;
}

/**
 * @brief Executes the command to list all loaded documents.
 * 
 * This method retrieves the list of loaded documents from the document register
 * and displays them using the CLI. If no documents are loaded, it shows an error message.
 */
void ListLoadedDocumentsCommand::execute() {
    if (documentRegister->getDocumentCount() == 0) {
        cli->error("No documents loaded.");
        return;
    }

    vector<Document*> documents = documentRegister->getDocuments();
    string documentList;

    for(Document* doc : documents) {
        documentList += doc->getDocName() + "\n";
    }
    cli->listDocuments(documentList);
}

/**
 * @brief Undoes the last executed command of listing loaded documents.
 * 
 * This command is not undoable, so this method does nothing.
 */
void ListLoadedDocumentsCommand::undo() {
}

/**
 * @brief Checks if the command is undoable.
 * 
 * @return bool Returns false since this command cannot be undone.
 */
bool ListLoadedDocumentsCommand::isUndoable() const {
    return false;
}