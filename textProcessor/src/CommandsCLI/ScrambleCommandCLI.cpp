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
 * @brief Displays a success message when the scramble command is undone successfully.
 * 
 * This method is called when the user successfully undoes the last scramble command.
 */
void ScrambleCommandCLI::successUndo() {
    cout << "Scramble command undone successfully." << endl;
}

