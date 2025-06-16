#include "../../headers/Commands/SaveCommand.hpp"

/**
 * @file SaveCommand.cpp
 * @author MK
 * @brief A command to save the active document in the text processor application.
 */
SaveCommand::SaveCommand(ActiveDocument* activeDocument, SaveCommandCLI* cli,DocumentRegister* documentRegister)
{
    this->activeDocument = activeDocument;
    this->cli = cli;
    this->documentRegister = documentRegister;
}

/**
 * @brief gets the name of the command.
 * @return string The name of the command.
 * 
 */
string SaveCommand::getName() const 
{
    return "Save";
}

/**
 * @brief Executes the command to save the active document.
 * 
 * This method checks if the active document has changed. If it has not changed, it informs the user.
 * If it has changed, it attempts to save the document using the document register.
 * If an error occurs during saving, it catches the exception and displays an error message.
 */
void SaveCommand::execute() 
{
    Document* docToSave = activeDocument->getActiveDocument();
    if(!docToSave) {
        cli->noActiveDocumentSet();
        return;
    }

    if(!docToSave->getHasChanged())
    {
        cli->documentHasntChanged();
        return;
    }

    try{
        documentRegister->saveDocument(docToSave);
    }
    catch(const runtime_error& e) {
        cli->error(string(e.what()));
    }

    cli->success();
}

bool SaveCommand::isUndoable() const {
    return false;
}
