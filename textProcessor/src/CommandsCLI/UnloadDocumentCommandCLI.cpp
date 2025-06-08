#include "../../headers/CommandsCLI/UnloadDocumentCommandCLI.hpp"


void UnloadDocumentCommandCLI::success() {
    cout << "Document unloaded successfully" << endl;
}

void UnloadDocumentCommandCLI::error(string message) {
    cout << message << endl;
}

string UnloadDocumentCommandCLI::getDocPathToUnload() {
    string docPath;
    cout << "Enter the path of the document to unload: " << endl;
    getline(cin, docPath);

    return docPath;
}

void UnloadDocumentCommandCLI::docHasChanged() {
    cout << "The document has changed since last save." << endl;
}

bool UnloadDocumentCommandCLI::saveQuery() {
    cout << "Do you want to save document before unload? Y/N" << endl;
    
    string answer;
    while(true){
        getline(cin, answer);
    
        if(answer == "Y")
        {
            return true;
        }
        else if (answer == "N"){
            return false;
        }
        else {
            cout << "Try again Y/N" << endl;
            answer.clear();
        }
    }
}

void UnloadDocumentCommandCLI::undo() {
    cout << "To undo unload document command, call load document command" << endl;
}