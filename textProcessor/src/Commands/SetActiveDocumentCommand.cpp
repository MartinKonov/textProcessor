#include "../../headers/Commands/SetActiveDocumentCommand.hpp"

SetActiveDocumentCommand::SetActiveDocumentCommand(SetActiveDocumentCommandCLI* setActiveDocumentCLI, ActiveDocument* activeDocument) {
    this->setActiveDocumentCLI = setActiveDocumentCLI;
    this->activeDocument = activeDocument;
}

string SetActiveDocumentCommand::getName() const {
    return "Set Active Document";
}

void SetActiveDocumentCommand::execute() {
    string docName = setActiveDocumentCLI->getDocPath();

    try {
        if(activeDocument->getActiveDocument()) {
            previousActiveDocumentName = activeDocument->getActiveDocument()->getDocName();
        }
        activeDocument->setActiveDocument(docName);
    } catch (runtime_error& e) {
        setActiveDocumentCLI->error(e.what());
        previousActiveDocumentName.clear();
        return;
    }
    
    setActiveDocumentCLI->success();
}

void SetActiveDocumentCommand::undo() {
    if(previousActiveDocumentName.empty())
    {
        setActiveDocumentCLI->errorUndoPrevDocName();
    }

    try {
        activeDocument->setActiveDocument(previousActiveDocumentName);
    } catch(runtime_error& e)
    {
        setActiveDocumentCLI->errorUndo(e.what());
    }

}