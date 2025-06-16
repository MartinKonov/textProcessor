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
 * @brief successUndo method to indicate that the undo operation was successful.
 */
void RemoveRepeatsCommandCLI::successUndo() {
    cout << "Undo remove repeats successful." << endl;
}