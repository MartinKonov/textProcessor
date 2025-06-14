#include "../../headers/CommandsCLI/ScrambleCommandCLI.hpp"

/**
 * @file ScrambleCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the ScrambleCommand.
 */


/**
 * @brief Displays a success message when the scramble command is executed successfully.
 */
void ScrambleCommandCLI::success() {
    cout << "Scramble command executed successfully." << endl;
}
/**
 * @brief Displays an error message if there was an error while executing the scramble command.
 * 
 * @param message The error message to display (optional).
 */
void ScrambleCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}

/**
 * @brief Displays a message indicating that there is nothing to undo for the scramble command.
 * 
 * This method is called when the user tries to undo a scramble command that has not been executed.
 */
void ScrambleCommandCLI::nothingToUndo() {
    cout << "Nothing to undo for scramble command." << endl;
}

/**
 * @brief Displays an error message if there is no active document set before trying to scramble.
 * 
 * This method is called when the user attempts to execute the scramble command without an active document.
 */
void ScrambleCommandCLI::errorActiveDocument() {
    cerr << "Set an active document before trying to scramble." << endl;
}

/**
 * @brief Displays a success message when the scramble command is undone successfully.
 * 
 * This method is called when the user successfully undoes the last scramble command.
 */
void ScrambleCommandCLI::successUndo() {
    cout << "Scramble command undone successfully." << endl;
}

