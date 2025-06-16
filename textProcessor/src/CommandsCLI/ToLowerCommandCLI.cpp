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
 * @brief Displays a message indicating that the undo operation was successful.
 * 
 * This method is called when the ToLower command is successfully undone.
 */
void ToLowerCommandCLI::successUndo() {
    cout << "ToLower command undone successfully." << endl;
}