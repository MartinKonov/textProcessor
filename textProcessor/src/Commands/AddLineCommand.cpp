#include "../../headers/Commands/AddLineCommand.hpp"

AddLineCommand::AddLineCommand(AddLineCommandCLI* addLineCommandCLI, ActiveDocument* activeDocument) {
    this->addLineCommandCLI = addLineCommandCLI;
    this->activeDocument = activeDocument;
    this->docBeforeExecution = nullptr;
}

AddLineCommand::~AddLineCommand() {
    delete docBeforeExecution;
}

void AddLineCommand::execute() {
    if (!activeDocument->getActiveDocument()) {
        addLineCommandCLI->activeDocumentError();
        return;
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
    if(!docBeforeExecution){
        return;
    }

    string activeDocName = activeDocument->getActiveDocument()->getDocName();
    if(activeDocName != docBeforeExecution->getDocName())
    {
        addLineCommandCLI->error();
        delete docBeforeExecution;
        docBeforeExecution = nullptr;
        return;
    }

    if(*activeDocument->getActiveDocument() == *docBeforeExecution)
    {
        addLineCommandCLI->nothingChanged();
    }

    *activeDocument->getActiveDocument() = *docBeforeExecution;
    delete docBeforeExecution;
    docBeforeExecution = nullptr;
}

void AddLineCommand::setDocBeforeExecution(Document* currentActiveDocument)
{
    if(this->docBeforeExecution)
    {
        delete docBeforeExecution;
    }

    this->docBeforeExecution = new Document(*currentActiveDocument);
}
