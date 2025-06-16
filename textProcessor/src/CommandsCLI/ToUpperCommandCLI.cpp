#include "../../headers/CommandsCLI/ToUpperCommandCLI.hpp"


/**
 * @file ToUpperCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the ToUpperCommand.
 */

/**
 * @brief Displays an error message.
 * 
 * @param message The error message to display (optional).
 */
void ToUpperCommandCLI::success() {
    cout << "Content converted to uppercase successfully." << endl;
}

/**
 * @brief Displays a message indicating that the undo operation was successful.
 */
void ToUpperCommandCLI::successUndo() {
    cout << "ToUpper command undone successfully." << endl;
}