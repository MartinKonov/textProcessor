#include "../../headers/CommandsCLI/SetActiveDocumentCommandCLI.hpp"


void SetActiveDocumentCommandCLI::success() {
    cout << "Set active document successfully" << endl;
}

void SetActiveDocumentCommandCLI::error(string message) {
    cout << message << endl;
}


string SetActiveDocumentCommandCLI::getDocPath() {
    cout << "Enter the path of the document to be set as active: " << endl;
    string docPath;

    getline(cin, docPath);

    return docPath;
}

void SetActiveDocumentCommandCLI::errorUndoPrevDocName() {
    cout << "Nothing to undo. No previous active document found" << endl;
}

void SetActiveDocumentCommandCLI::errorUndo(string message) {
    cout << "Set active document command: " << message << endl;
}