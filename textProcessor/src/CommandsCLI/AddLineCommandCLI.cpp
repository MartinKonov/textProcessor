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

void AddLineCommandCLI::changedDocError() {
    cout << "The active document has changed since last call of this command. Undo is impossible" << endl;
}

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