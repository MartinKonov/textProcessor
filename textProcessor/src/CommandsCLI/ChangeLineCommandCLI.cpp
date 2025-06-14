#include "../../headers/CommandsCLI/ChangeLineCommandCLI.hpp"

/**
 * @file ChangeLineCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the ChangeLineCommand.
 */

/**
 * @brief Displays a success message when a line is changed successfully.
 * 
 * This method is called after the line change operation is executed successfully.
 */
void ChangeLineCommandCLI::success() {
    cout << "Line changed successfully." << endl;
}

/**
 * @brief Displays a success message when the undo operation for changing a line is successful.
 * 
 * This method is called after the undo operation for changing a line is executed successfully.
 */
void ChangeLineCommandCLI::successUndo() {
    cout << "Line change undone successfully." << endl;
}

/**
 * @brief Displays the document contents with line indices.
 * 
 * @param document The contents of the document to display.
 */
void ChangeLineCommandCLI::showDocumentWithIndices(string document) {
    cout << document << endl;
}


/**
 * @brief Displays an error message.
 * 
 * This method is called when an error occurs during the line change operation.
 * 
 * @param message The error message to display (optional).
 */
void ChangeLineCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}

/**
 * @brief Prompts the user for the new content of the line to change.
 * 
 * This method asks the user to input the new content for the line they want to change.
 * 
 * @return string The new content entered by the user.
 */
string ChangeLineCommandCLI::getNewLineContent() {
    cout << "Enter the new content for the line:" << endl;
    string newContent;
    getline(cin, newContent);
    return newContent;
}

 /**
  * @brief Prompts the user for the line number they want to change.
  * 
  * This method asks the user to input the line number they wish to change in the active document.
  * It validates the input and returns the line number as an integer.
  * 
  * @return int The line number to change.
  * @throws runtime_error if the input is invalid or empty.
  */
int ChangeLineCommandCLI::getLineNumberToChange() {
    cout << "Enter the line number to change:" << endl;
    string lineNumberStr;
    getline(cin, lineNumberStr);
    if (lineNumberStr.empty()) {
        throw runtime_error("Line number cannot be empty.");
    }
    try {
        return stoi(lineNumberStr);
    } catch (const invalid_argument&) {
        throw runtime_error("Invalid line number format.");
    }
}