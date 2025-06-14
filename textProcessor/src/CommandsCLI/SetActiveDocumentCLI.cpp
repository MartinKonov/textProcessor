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
 * @brief Displays an error message if the active document could not be set.
 * 
 * @param message The error message to display (optional).
 */
void SetActiveDocumentCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
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

/**
 * @brief Displays an error message if there is no previous active document to undo.
 * 
 * This method informs the user that there is nothing to undo because no previous active document was found.
 */
void SetActiveDocumentCommandCLI::errorUndoPrevDocName() {
    cerr << "Nothing to undo. No previous active document found" << endl;
}

/**
 * @brief Displays an error message if there was an error while undoing the last operation.
 * 
 * @param message The error message to display.
 */
void SetActiveDocumentCommandCLI::errorUndo(string message) {
    cerr << "Error: " << message << endl;
}