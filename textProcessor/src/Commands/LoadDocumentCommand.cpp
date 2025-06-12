#include "../../headers/Commands/LoadDocumentCommand.hpp"


LoadDocumentCommand::LoadDocumentCommand(LoadDocumentCommandCLI* loadDocumentCommandCLI, DocumentRegister* documentRegister) {
    this->loadDocumentCommandCLI = loadDocumentCommandCLI;
    this->documentRegister = documentRegister;
}

string LoadDocumentCommand::getName() const {
    return "Load Document";
}

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

bool LoadDocumentCommand::isUndoable() const {
    return false;
}