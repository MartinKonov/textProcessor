#include "../../headers/Commands/AddLineCommand.hpp"

AddLineCommand::AddLineCommand(AddLineCommandCLI* addLineCommandCLI) {
    addLineCommandCLI = addLineCommandCLI;
    activeDocument = ActiveDocument::getInstance();
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

    currentActiveDocument->addLine(line);

    addLineCommandCLI->success();
}

string AddLineCommand::getName() const {
    return "Add Line";
}

void AddLineCommand::undo() 
{
    //make a copy constructor of the document and keep it
    //to restore the document to its previous state
}

