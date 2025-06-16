/**
 * @file SetActiveDocumentCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the SetActiveDocumentCommand.
 */
#include "../../headers/CommandsCLI/SetActiveDocumentCommandCLI.hpp"


/**
 * @brief Sets the active document successfully.
 * 
 * This method prints a success message to the console.
 */
void SetActiveDocumentCommandCLI::success() {
    cout << "Set active document successfully" << endl;
}

/**
 * @brief Prompts the user to enter the document path and returns it.
 * 
 * This method asks the user to input the path of the document to be set as active.
 * 
 * @return string The path of the document.
 */
string SetActiveDocumentCommandCLI::getDocPath() {
    cout << "Enter the path of the document to be set as active: " << endl;
    string docPath;

    getline(cin, docPath);

    return docPath;
}
