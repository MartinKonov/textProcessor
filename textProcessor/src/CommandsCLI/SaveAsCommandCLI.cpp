/**
 * @file SaveAsCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the SaveAsCommand.
 */
#include "../../headers/CommandsCLI/SaveAsCommandCLI.hpp"

/**
 * @brief Displays a success message when the document is saved successfully.
 */
void SaveAsCommandCLI::success(){
    cout << "Document saved successfully" << endl;
}

/**
 * @brief Displays a message indicating that there is nothing to save.
 */
void SaveAsCommandCLI::documentHasntChanged(){
    cout << "Nothing to save." << endl;
}

void SaveAsCommandCLI::noActiveDocumentSet() {
    cout << "Set an active document before trying to save." << endl;
}

/**
 * @brief Displays an error message if there was an error while saving the document.
 * 
 * @param message The error message to display (optional).
 */
void SaveAsCommandCLI::error(string message) {
    cerr << "Error: " + message << endl;
}

/**
 * @brief Prompts the user to enter a new document name and returns it.
 * 
 * @return string The new document name entered by the user.
 */
string SaveAsCommandCLI::getNewDocName() {
    cout << "Enter the new document name" << endl;
    string newDocName;
    getline(cin, newDocName);
    return newDocName;
}
