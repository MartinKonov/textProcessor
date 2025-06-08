#include "../../headers/Commands/SaveCommand.hpp"


SaveCommand::SaveCommand(ActiveDocument* activeDocument, SaveCommandCLI* saveCommandCLI,DocumentRegister* documentRegister)
{
    this->activeDocument = activeDocument;
    this->saveCommandCLI = saveCommandCLI;
    this->documentRegister = documentRegister;
}


string SaveCommand::getName() const 
{
    return "Save";
}

void SaveCommand::execute() 
{
    Document* docToSave = activeDocument->getActiveDocument();

    if(!docToSave->getHasChanged())
    {
        saveCommandCLI->documentHasntChanged();
        return;
    }

    try{
        documentRegister->saveDocument(docToSave);
    }
    catch(const runtime_error& e) {
        saveCommandCLI->error(string(e.what()));
    }
}

void SaveCommand::undo() {
    return;
}