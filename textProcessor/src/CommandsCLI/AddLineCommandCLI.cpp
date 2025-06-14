#include "../../headers/CommandsCLI/AddLineCommandCLI.hpp"

/**
 * @brief Gets the line input from the user.
 * 
 * This method prompts the user to enter a line and returns the input as a string.
 * 
 * @return string The line input from the user.
 */
string AddLineCommandCLI::getLineInput() {
    string line;
    cout << "Enter the line to add: ";
    getline(cin, line);
    return line;
}

/**
 * @brief Displays an error message if the active document has changed.
 * 
 * This method prints an error message to the console indicating that the active document has changed
 * since the last call of this command, making undo impossible.
 * 
 * @param message The error message to display (optional).
 */
void AddLineCommandCLI::error(string message) {
    cerr << "Error: The active document has changed since last call of this command. Undo is impossible" << endl;
}

/**
 * @brief Displays an error message if there is no active document set.
 * 
 * This method prints an error message to the console indicating that there is no active document set,
 * which is required for the command to execute successfully.
 */
void AddLineCommandCLI::activeDocumentError(){
    cout << "Error: No active document set" << endl;
}

/**
 * @brief Displays a message when nothing has changed to undo.
 * 
 * This method prints a message to the console indicating that there is nothing to undo,
 * which is useful when the user tries to undo an operation that has not been performed.
 */
void AddLineCommandCLI::nothingChanged() {
    cout << "Nothing to undo" << endl;
}

/**
 * @brief Displays a success message after adding a line.
 * 
 * This method prints a success message to the console.
 */
void AddLineCommandCLI::success() {
    cout << "Line added successfully." << endl;
}