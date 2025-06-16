#include "../../headers/CommandsCLI/ExitCommandCLI.hpp"

/**
 * @file ExitCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the ExitCommand.
 */



void ExitCommandCLI::showDocumentHasChangedMessage(string docName) {
    cout << "Document '" << docName << "' has unsaved changes." << endl;
}

bool ExitCommandCLI::getDocumentSaveConfirmation() {
    cout << "Do you want to save changes? (y/n): ";
    string response;
    getline(cin, response);
    return response == "y" || response == "Y";
}