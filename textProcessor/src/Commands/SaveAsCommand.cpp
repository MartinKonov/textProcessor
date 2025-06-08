#include "../../headers/Commands/SaveAsCommand.hpp"


string SaveAsCommand::getName() const {
    return "Save as";
}

void SaveAsCommand::execute() {
    Document* docToSave = activeDocument->getActiveDocument();

    string newDocName = saveAsCommandCLI->getNewDocName();

    if(!docToSave->getHasChanged())
    {
        saveAsCommandCLI->documentHasntChanged();
        return;
    }

    try{
        documentRegister->saveAsDocument(docToSave, newDocName);
    }
    catch(const runtime_error& e) {
        saveAsCommandCLI->error(string(e.what()));
    }
}

void SaveAsCommand::undo(){
    
}