#include "../../headers/CommandsCLI/SaveAsCommandCLI.hpp"


void SaveAsCommandCLI::success(){
    cout << "Document saved successfully" << endl;
}

void SaveAsCommandCLI::documentHasntChanged(){
    cout << "Nothing to save." << endl;
}

void SaveAsCommandCLI::error(string message) {
    cout << "SaveCommand::execute() " + message << endl;
}

string SaveAsCommandCLI::getNewDocName() {
    cout << "Enter the new document name" << endl;
    string newDocName;
    getline(cin, newDocName);
    return newDocName;
}
