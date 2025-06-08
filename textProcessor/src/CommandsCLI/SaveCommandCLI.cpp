#include "../../headers/CommandsCLI/SaveCommandCLI.hpp"


void SaveCommandCLI::success(){
    cout << "Document saved successfully" << endl;
}

void SaveCommandCLI::documentHasntChanged(){
    cout << "Nothing to save." << endl;
}

void SaveCommandCLI::error(string message) {
    cout << "SaveCommand::execute() " + message << endl;
}

