#include "../../headers/CommandsCLI/TrimLeadingCommandCLI.hpp"


/**
 * @file TrimLeadingCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the TrimLeadingCommand.
 */


/**
 * @brief Displays a success message indicating that leading whitespaces have been trimmed successfully.
 * 
 * This method is called after the trim leading command has been executed successfully.
 */
void TrimLeadingCommandCLI::success() {
    cout << "Leading whitespaces trimmed successfully." << endl;
}

void TrimLeadingCommandCLI::successUndo() {
    cout << "Trim leading command undone successfully." << endl;
}