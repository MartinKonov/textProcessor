#include "../../headers/Commands/ViewDocumentCommand.hpp"

/**
 * @file ViewDocumentCommand.cpp
 * @author MK
 * @brief A command to view the content of a document in the text processor application.
 */
ViewDocumentCommand::ViewDocumentCommand(ViewDocumentCommandCLI* cli, ActiveFormatter* activeFormatter,ActiveDocument* activeDocument, DocumentRegister* documentRegister) {
    this->cli = cli;
    this->activeDocument = activeDocument;
    this->activeFormatter = activeFormatter;
    this->documentRegister = documentRegister;
}

/**
 * @brief Returns the name of the command.
 * 
 * This method provides the name of the command, which is used for display purposes in the CLI.
 * 
 * @return string The name of the command.
 */
string ViewDocumentCommand::getName() const {
    return "View Document";
}

/**
 * @brief Executes the command to view a document.
 * This method prompts the user to choose between viewing the active document or another document.
 * If the active document is not set, it defaults to viewing another document.
 * It retrieves the contents of the selected document and formats it using the active formatter.
 */
void ViewDocumentCommand::execute() {
    int choice;
    if(!activeDocument->getActiveDocument()) {
        choice = OTHER_DOC_CHOICE;
    }
    else{
        choice = cli->getChoiceActiveDocOrOtherDoc();
    }

    string docContents;
    if (choice == ACTIVE_DOC_CHOICE) {
        docContents = activeDocument->getActiveDocument()->getContents();
    } else if(choice == OTHER_DOC_CHOICE) {
        string documentToPrint = cli->getDocumentToPrint();
        try {
            docContents = documentRegister->getDocument(documentToPrint)->getContents(); 
        } catch (runtime_error &e) {
            cli->error(e.what());
            return;
        }
    } else {
        cli->error("Invalid choice");
        return;
    }
    string contentsToPrint = activeFormatter->getFormattedString(docContents);
    cli->printContents(contentsToPrint);
}

/**
 * @brief Undoes the last executed command of viewing a document.
 * 
 * This method does not perform any undo operation as viewing a document is not considered undoable.
 */
void ViewDocumentCommand::undo() {

}

/**
 * @brief ViewDocumentCommand is not undoable.
 */
bool ViewDocumentCommand::isUndoable() const{
    return false;
}

