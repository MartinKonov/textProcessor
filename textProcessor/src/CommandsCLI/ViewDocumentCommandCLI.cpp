#include "../../headers/CommandsCLI/ViewDocumentCommandCLI.hpp"


void ViewDocumentCommandCLI::success() {

}

void ViewDocumentCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}

int ViewDocumentCommandCLI::getChoiceActiveDocOrOtherDoc() {
    cout << "Enter 0 to view active document, or 1 to view other document" << endl;
    string choice;
    getline(cin, choice);
    return stoi(choice);
}

string ViewDocumentCommandCLI::getDocumentToPrint() {
    cout << "Enter the full path of the document to view:" << endl;
    string path;
    getline(cin, path);
    return path;
}

void ViewDocumentCommandCLI::printContents(string contentsToPrint) {
    cout << contentsToPrint << endl;
}