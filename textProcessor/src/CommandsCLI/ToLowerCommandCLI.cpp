#include "../../headers/CommandsCLI/ToLowerCommandCLI.hpp"

/**
 * @file ToLowerCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the ToLowerCommand.
 */

/**
 * @brief Displays a success message after converting content to lowercase.
 * 
 * This method is called when the ToLower command is executed successfully.
 */
void ToLowerCommandCLI::success() {
    cout << "Content converted to lowercase successfully." << endl;
}

/**
 * @brief Displays an error message.
 * 
 * This method is called when there is an error during the execution of the ToLower command.
 * 
 * @param message The error message to display (optional).
 */
void ToLowerCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}


/**
 * @brief Displays a message indicating that there is nothing to undo for the ToLower command.
 * 
 * This method is called when the user attempts to undo the ToLower command but there is no previous state to revert to.
 */
void ToLowerCommandCLI::nothingToUndo() {
    cout << "Nothing to undo for toLower command." << endl;
}

/**
 * @brief Displays a message indicating that the undo operation was successful.
 * 
 * This method is called when the ToLower command is successfully undone.
 */
void ToLowerCommandCLI::successUndo() {
    cout << "ToLower command undone successfully." << endl;
}