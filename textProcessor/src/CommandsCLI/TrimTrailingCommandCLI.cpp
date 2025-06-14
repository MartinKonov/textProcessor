#include "../../headers/CommandsCLI/TrimTrailingCommandCLI.hpp"

/**
 * @file TrimTrailingCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the TrimTrailingCommand.
 */

/**
 * @brief Displays a success message indicating that trailing whitespaces have been trimmed successfully.
 * 
 * This method is called after the trim trailing command has been executed successfully.
 */
void TrimTrailingCommandCLI::success() {
    cout << "Trailing whitespaces trimmed successfully." << endl;
}

/**
 * @brief Displays an error message when no active document is set.
 * 
 * This method informs the user that there is no active document available for the trim trailing command.
 */
void TrimTrailingCommandCLI::noActiveDocumentSet() {
    cerr << "Error: No active document set." << endl;
}

/**
 * @brief Displays an error message.
 * 
 * @param message The error message to display (optional).
 */
void TrimTrailingCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}


/**
 * @brief Indicates that there is nothing to undo for the trim trailing command.
 */
void TrimTrailingCommandCLI::nothingToUndo() {
    cerr << "Error: Nothing to undo for trim trailing." << endl;
}
