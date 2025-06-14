#include "../../headers/CommandsCLI/RemoveLineCommandCLI.hpp"


/**
 * @file RemoveLineCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the RemoveLineCommand.
 */


 /**
  * @brief Displays a success message after removing a line.
  */
void RemoveLineCommandCLI::success() {
    cout << "Line removed successfully." << endl;
}

/**
 * @brief Displays an error message.
 * 
 * @param message The error message to display (optional).
 */
void RemoveLineCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}

/**
 * @brief Displays the document contents with line indices.
 * 
 * @param documentContents The contents of the document to display.
 */
void RemoveLineCommandCLI::showDocumentWithIndices(string documentContents){
    cout << "Document contents with line indices:" << endl;
    cout << documentContents << endl;
}

/**
 * @brief Prompts the user to enter the line number to remove.
 * 
 * @return string The line number entered by the user.
 */
string RemoveLineCommandCLI::getLineNumberToRemove() {
    cout << "Enter the line number to remove:" << endl;
    string lineNumber;
    getline(cin, lineNumber);
    return lineNumber;
}

/**
 * @brief Displays a success message after undoing the line removal.
 */
void RemoveLineCommandCLI::successUndo() {
    cout << "Undone line removal successfully." << endl;
}


