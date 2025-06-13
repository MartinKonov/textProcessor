#include "../../headers/Commands/LoadDocumentCommand.hpp"

/**
 * @file LoadDocumentCommand.cpp
 * @author MK
 * @brief A command to load a document in the text processor application.
 */
LoadDocumentCommand::LoadDocumentCommand(LoadDocumentCommandCLI* loadDocumentCommandCLI, DocumentRegister* documentRegister) {
    this->loadDocumentCommandCLI = loadDocumentCommandCLI;
    this->documentRegister = documentRegister;
}

/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string LoadDocumentCommand::getName() const {
    return "Load Document";
}

/**
 * @brief Executes the command to load a document.
 * 
 * This method retrieves the document file path from the CLI,
 * attempts to add the document to the document register,
 * and handles any errors that may occur during the process.
 */
void LoadDocumentCommand::execute() {

    string docFilePath = loadDocumentCommandCLI->getDocFilePath();

    try {
        documentRegister->addDocument(docFilePath);
    } catch(runtime_error& e) {
        loadDocumentCommandCLI->error(e.what());
        return;
    }
    loadDocumentCommandCLI->success();
}

/**
 * @brief Undoes the load document command.
 * 
 * This method does not perform any action as loading a document is not undoable.
 */
bool LoadDocumentCommand::isUndoable() const {
    return false;
}