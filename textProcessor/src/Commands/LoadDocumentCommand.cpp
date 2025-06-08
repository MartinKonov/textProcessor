#include "../../headers/Commands/LoadDocumentCommand.hpp"


LoadDocumentCommand::LoadDocumentCommand(LoadDocumentCommandCLI* loadDocumentCommandCLI, DocumentRegister* documentRegister) {
    this->loadDoucmentCommandCLI = loadDocumentCommandCLI;
    this->documentRegister = documentRegister;
}

string LoadDocumentCommand::getName() const {
    return "Load Document";
}

void LoadDocumentCommand::execute() {

    string docFilePath = loadDoucmentCommandCLI->getDocFilePath();

    try {
        documentRegister->addDocument(docFilePath);
    } catch(runtime_error& e) {
        loadDoucmentCommandCLI->error(e.what());
        return;
    }
    loadDoucmentCommandCLI->success();
}

void LoadDocumentCommand::undo() {
    loadDoucmentCommandCLI->undo();
}