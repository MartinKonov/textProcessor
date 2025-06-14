#include "../../headers/CommandsCLI/RemoveRepeatsCommandCLI.hpp"

/**
 * @file RemoveRepeatsCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the RemoveRepeatsCommand.
 */

/**
 * @brief success method to indicate that the command was executed successfully.
 */
void RemoveRepeatsCommandCLI::success() {
    cout << "Repeated lines removed successfully." << endl;
}

/**
 * @brief errorActiveDocument method to indicate that there is no active document set.
 */
void RemoveRepeatsCommandCLI::errorActiveDocument() {
    cerr << "Error: Set an active document before trying to remove repeats." << endl;
}

/**
 * @brief error method to display an error message.
 * 
 * @param message The error message to display.
 */
void RemoveRepeatsCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}

/**
 * @brief nothingToUndo method to indicate that there is nothing to undo.
 */
void RemoveRepeatsCommandCLI::nothingToUndo() {
    cout << "Nothing to undo." << endl;
}

/**
 * @brief successUndo method to indicate that the undo operation was successful.
 */
void RemoveRepeatsCommandCLI::successUndo() {
    cout << "Undo remove repeats successful." << endl;
}