#include "../../headers/CommandsCLI/ViewAllMacrosCommandCLI.hpp"

/**
 * @file ViewAllMacrosCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the ViewAllMacrosCommand.
*/


/**
 * @brief error method to display an error message.
 */
void ViewAllMacrosCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}

/**
 * @brief Displays the current macros in a formatted way.
 * 
 * @param serializedMacros The serialized string representation of the current macros.
 */
void ViewAllMacrosCommandCLI::showCurrentMacros(string serializedMacros) {
    cout << "Current Macros:" << endl;
    cout << serializedMacros << endl;
}