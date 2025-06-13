#include "../../headers/Commands/SaveAsCommand.hpp"


string SaveAsCommand::getName() const {
    return "Save as";
}

void SaveAsCommand::execute() {
    Document* docToSave = activeDocument->getActiveDocument();

    string newDocName = saveAsCommandCLI->getNewDocName();

    try{
        documentRegister->saveAsDocument(docToSave, newDocName);
    }
    catch(const runtime_error& e) {
        saveAsCommandCLI->error(string(e.what()));
    }
}

bool SaveAsCommand::isUndoable() const {
    return false;
}