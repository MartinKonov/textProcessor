#include "../../headers/CommandsCLI/LoadDocumentCommandCLI.hpp"


void LoadDocumentCommandCLI::success() {
    cout << "Document loaded successfully" << endl; 
}

string LoadDocumentCommandCLI::getDocFilePath() {
    string docFilePath;

    cout << "Enter the document full file path: " << endl;
    getline(cin, docFilePath);

    return docFilePath;
}

void LoadDocumentCommandCLI::error(string message) {
    cout << "Error loading file: " << message << endl;
}

void LoadDocumentCommandCLI::undo() {
    cout << "To undo load document command, call unload document command" << endl;
}