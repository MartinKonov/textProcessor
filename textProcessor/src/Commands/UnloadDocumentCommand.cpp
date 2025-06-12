#include "../../headers/Commands/UnloadDocumentCommand.hpp"

UnloadDocumentCommand::UnloadDocumentCommand(UnloadDocumentCommandCLI* unloadDocumentCommandCLI, DocumentRegister* documentRegister, ActiveDocument* activeDocument) {
    this->unloadDocumentCommandCLI = unloadDocumentCommandCLI;
    this->documentRegister = documentRegister;
    this->activeDocument = activeDocument;
}


string UnloadDocumentCommand::getName() const {
    return "Unload document";
}

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

bool UnloadDocumentCommand::isUndoable() const {
    return false;
}