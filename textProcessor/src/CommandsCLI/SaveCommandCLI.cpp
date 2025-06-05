#include "../../headers/CommandsCLI/SaveCommandCLI.hpp"


void SaveCommandCLI::success(){
    cout << "Document saved successfully" << endl;
}

void SaveCommandCLI::documentHasntChanged(){
    cout << "Nothing to save." << endl;
}

void SaveCommandCLI::errorSaving(string err) {
    cout << "SaveCommand::execute() " + err << endl;
}

