#include "../../headers/Commands/ExitCommand.hpp"

/**
 * @file ExitCommand.cpp
 * @author MK
 * @brief A command to exit the text processor application, handling document saving and cleanup.
 */
ExitCommand::ExitCommand(ExitCommandCLI* exitCommandCLI, DocumentRegister* documentRegister) {
    this->exitCommandCLI = exitCommandCLI;
    this->documentRegister = documentRegister;
}

/**
 * @brief gets the name of the command.
 */
string ExitCommand::getName() const {
    return "Exit";
}

/**
 * @brief executes the exit command.
 * It checks if there are any documents that have changed and prompts the user to save them before exiting.
 */
void ExitCommand::execute() {
    if (documentRegister->getDocumentCount() == 0) {
        return;
    }

    vector<Document*> documents = documentRegister->getDocuments();

    for (Document* document : documents) {
        if (document->getHasChanged()) {
            exitCommandCLI->showDocumentHasChangedMessage(document->getDocName());
            if (!exitCommandCLI->getDocumentSaveConfirmation()) {
                continue;
            }
            documentRegister->saveDocument(document);
        }
    }
}

/**
 * @brief exit is not undoable.
 */
bool ExitCommand::isUndoable() const {
    return false;
}