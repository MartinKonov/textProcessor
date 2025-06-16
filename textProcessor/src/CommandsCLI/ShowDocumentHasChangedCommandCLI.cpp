#include "../../headers/CommandsCLI/ShowDocumentHasChangedCommandCLI.hpp"


/**
 * @file ShowDocumentHasChangedCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the ShowDocumentHasChangedCommand.
 */

/**
 * @brief Displays whether the active document has changed.
 */
void ShowDocumentHasChangedCommandCLI::showDocumentHasChanged(bool hasChanged) {
    if (hasChanged) {
        cout << "The active document has changed." << endl;
    } else {
        cout << "The active document has not changed." << endl;
    }
}

/**
 * @brief Displays an error message.
 * 
 * @param message The error message to display.
 */
void ShowDocumentHasChangedCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}