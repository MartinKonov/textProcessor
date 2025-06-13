#include "../../headers/Commands/ListLoadedDocumentsCommand.hpp"


ListLoadedDocumentsCommand::ListLoadedDocumentsCommand(ListLoadedDocumentsCommandCLI* cli, DocumentRegister* documentRegister) {
    this->cli = cli;
    this->documentRegister = documentRegister;
}


string ListLoadedDocumentsCommand::getName() const {
    return "List Loaded Documents";
}

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

void ListLoadedDocumentsCommand::undo() {
}

bool ListLoadedDocumentsCommand::isUndoable() const {
    return false;
}