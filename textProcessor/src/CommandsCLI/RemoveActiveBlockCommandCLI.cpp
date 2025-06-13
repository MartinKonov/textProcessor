#include "../../headers/CommandsCLI/RemoveActiveBlockCommandCLI.hpp"


/**
 * @file RemoveActiveBlockCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the RemoveActiveBlockCommand.
 */
void RemoveActiveBlockCommandCLI::success() {
    cout << "Active block removed successfully." << endl;
}

/**
 * @brief Displays an error message if the active block could not be removed.
 * 
 * @param message The error message to display (optional).
 */
void RemoveActiveBlockCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}

/**
 * @brief Displays a message indicating that there is nothing to undo.
 */
void RemoveActiveBlockCommandCLI::nothingToUndo() {
    cout << "Nothing to undo." << endl;
}

/**
 * @brief Displays a message indicating that the document has changed since the last operation.
 */
void RemoveActiveBlockCommandCLI::documentHasChanged() {
    cerr << "The document has changed since last operation. Cannot undo." << endl;
}

/**
 * @brief Displays an error message if there was an error while undoing the last operation.
 * 
 * @param message The error message to display.
 */
void RemoveActiveBlockCommandCLI::errorUndo(string message) {
    cerr << "Error while undo: " << message << endl;
}