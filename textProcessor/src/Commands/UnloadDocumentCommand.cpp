#include "../../headers/Commands/UnloadDocumentCommand.hpp"

/**
 * @file UnloadDocumentCommand.cpp
 * @author MK
 * @brief A command to unload a document from the text processor application.
 */
UnloadDocumentCommand::UnloadDocumentCommand(UnloadDocumentCommandCLI* unloadDocumentCommandCLI, DocumentRegister* documentRegister, ActiveDocument* activeDocument) {
    this->unloadDocumentCommandCLI = unloadDocumentCommandCLI;
    this->documentRegister = documentRegister;
    this->activeDocument = activeDocument;
}


/**
 * @brief gets the name of the command.
 * @return string The name of the command.
 */
string UnloadDocumentCommand::getName() const {
    return "Unload document";
}

/**
 * @brief Executes the command to unload a document.
 * 
 * This method retrieves the document path from the CLI, checks if the document exists in the register,
 * and if it has changed, prompts the user to save changes before unloading it.
 * If the document is successfully unloaded, it removes it from the active document.
 */
void UnloadDocumentCommand::execute() {

    string docPathToUnload = unloadDocumentCommandCLI->getDocPathToUnload();

    Document* docToUnload;

    try {
        docToUnload = documentRegister->getDocument(docPathToUnload);
    } catch(runtime_error& e) {
        unloadDocumentCommandCLI->error(e.what());
        return;
    }

    handleDocHasChanged(docToUnload);

    try {
        documentRegister->removeDocument(docPathToUnload);
    }
    catch(runtime_error& e){
        unloadDocumentCommandCLI->error(e.what());
        return;
    }

    activeDocument->removeActiveDocument();

    unloadDocumentCommandCLI->success();
}

/**
 * @brief Handles the case when the document has changed.
 * 
 * If the document has changed, it prompts the user to save changes before unloading it.
 * If the user chooses not to save, it returns without unloading the document.
 * If the user chooses to save, it attempts to save the document and catches any runtime errors.
 * 
 * @param document The document that has changed.
 */
void UnloadDocumentCommand::handleDocHasChanged(Document* document) {
    if(!document->getHasChanged()) {
        return;
    }

    unloadDocumentCommandCLI->docHasChanged();
    if(!unloadDocumentCommandCLI->saveQuery()) {
        return;
    }

    try {
        documentRegister->saveDocument(document);
    } catch (runtime_error& e) {
        unloadDocumentCommandCLI->error(e.what());
    }
}

/**
 * @brief This method does not perform any undo operation as unloading a document is considered undoable.
 */
bool UnloadDocumentCommand::isUndoable() const {
    return false;
}