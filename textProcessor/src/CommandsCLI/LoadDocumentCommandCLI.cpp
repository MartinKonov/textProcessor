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
    cerr << "Error loading file: " << message << endl;
}
