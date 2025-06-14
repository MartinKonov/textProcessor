#include "../../headers/CommandsCLI/TrimLeadingCommandCLI.hpp"


/**
 * @file TrimLeadingCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the TrimLeadingCommand.
 */


/**
 * @brief Displays a success message indicating that leading whitespaces have been trimmed successfully.
 * 
 * This method is called after the trim leading command has been executed successfully.
 */
void TrimLeadingCommandCLI::success() {
    cout << "Leading whitespaces trimmed successfully." << endl;
}
/**
 * @brief Displays an error message when no active document is set.
 * 
 * This method informs the user that there is no active document available for the trim leading command.
 */
void TrimLeadingCommandCLI::noActiveDocumentSet() {
    cerr << "Error: No active document set." << endl;
}
/**
 * @brief Displays an error message.
 * 
 * @param message The error message to display (optional).
 */
void TrimLeadingCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}
/**
 * @brief Indicates that there is nothing to undo for the trim leading command.
 */
void TrimLeadingCommandCLI::nothingToUndo() {
    cerr << "Error: Nothing to undo for trim leading." << endl;
}

void TrimLeadingCommandCLI::successUndo() {
    cout << "Trim leading command undone successfully." << endl;
}