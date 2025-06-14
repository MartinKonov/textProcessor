#include "../../headers/Commands/SaveAsCommand.hpp"

/**
 * @file SaveAsCommand.cpp
 * @author MK
 * @brief A command to save the active document under a new name in the text processor application.
 */

 /**
  * @brief Returns the name of the command.
  */
string SaveAsCommand::getName() const {
    return "Save as";
}

/**
 * @brief Executes the command to save the active document under a new name.
 * 
 * This method retrieves the new document name from the CLI and attempts to save the active document.
 * If an error occurs during saving, it catches the exception and displays an error message.
 */
void SaveAsCommand::execute() {
    Document* docToSave = activeDocument->getActiveDocument();

    if(!docToSave) {
        saveAsCommandCLI->noActiveDocumentSet();
        return;
    }

    string newDocName = saveAsCommandCLI->getNewDocName();

    try{
        documentRegister->saveAsDocument(docToSave, newDocName);
    }
    catch(const runtime_error& e) {
        saveAsCommandCLI->error(string(e.what()));
    }
}

/**
 * @brief Undoes the last executed command of saving the document.
 * 
 * This method does not perform any undo operation as saving a document is not considered undoable.
 */
bool SaveAsCommand::isUndoable() const {
    return false;
}