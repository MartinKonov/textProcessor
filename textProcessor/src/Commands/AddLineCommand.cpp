#include "../../headers/Commands/AddLineCommand.hpp"

AddLineCommand::AddLineCommand(AddLineCommandCLI* addLineCommandCLI, ActiveDocument* activeDocument) {
    this->addLineCommandCLI = addLineCommandCLI;
    this->activeDocument = activeDocument;
    this->docBeforeExecution = nullptr;
}

AddLineCommand::~AddLineCommand() {
    //Releasing the memory allocated for addLineCommandIO and activeDocument is not necessary here since it is managed by another component.
}

void AddLineCommand::execute() {
    if (!activeDocument->getActiveDocument()) {
        throw std::runtime_error("AddLineCommand::execute: No active document set");
    }
    
    string line = addLineCommandCLI->getLineInput();
    Document* currentActiveDocument = activeDocument->getActiveDocument();
    
    this->docBeforeExecution = new Document(*currentActiveDocument);

    currentActiveDocument->addLine(line);

    addLineCommandCLI->success();
}

string AddLineCommand::getName() const {
    return "Add Line";
}

void AddLineCommand::undo() 
{
    string activeDocName = activeDocument->getActiveDocument()->getDocName();
    if(activeDocName != docBeforeExecution->getDocName())
    {
        addLineCommandCLI->changedDocError();
    }

    if(activeDocument->getActiveDocument() == docBeforeExecution)
    {
        addLineCommandCLI->nothingChanged();
    }

    *activeDocument->getActiveDocument() = *docBeforeExecution;
}

void AddLineCommand::setDocBeforeExecution(Document* currentActiveDocument)
{
    if(this->docBeforeExecution)
    {
        delete docBeforeExecution;
    }

    this->docBeforeExecution = new Document(*currentActiveDocument);
}
