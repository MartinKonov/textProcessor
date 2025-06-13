#include "../../headers/Commands/ViewDocumentCommand.hpp"


ViewDocumentCommand::ViewDocumentCommand(ViewDocumentCommandCLI* cli, ActiveFormatter* activeFormatter,ActiveDocument* activeDocument, DocumentRegister* documentRegister) {
    this->cli = cli;
    this->activeDocument = activeDocument;
    this->activeFormatter = activeFormatter;
    this->documentRegister = documentRegister;
}

string ViewDocumentCommand::getName() const {
    return "View Document";
}

void ViewDocumentCommand::execute() {
    int choice;
    if(!activeDocument->getActiveDocument()) {
        choice = OTHER_DOC_CHOICE;
    }
    else{
        choice = cli->getChoiceActiveDocOrOtherDoc();
    }

    string contentsToPrint;
    if (choice == ACTIVE_DOC_CHOICE) {
        contentsToPrint = activeFormatter->getFormattedString(activeDocument->getActiveDocument()->getContents());
    } else if(choice == OTHER_DOC_CHOICE) {
        string documentToPrint = cli->getDocumentToPrint();
        try {
            contentsToPrint = documentRegister->getDocument(documentToPrint)->getContents();
        } catch (runtime_error &e) {
            cli->error(e.what());
        }
    } else {
        cli->error("Invalid choice");
    }

    cli->printContents(contentsToPrint);
}

void ViewDocumentCommand::undo() {

}

bool ViewDocumentCommand::isUndoable() const{
    return false;
}

