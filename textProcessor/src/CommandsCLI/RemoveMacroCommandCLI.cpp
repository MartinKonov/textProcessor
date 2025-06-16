#include "../../headers/CommandsCLI/RemoveMacroCommandCLI.hpp"



/**
 * @file RemoveMacroCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the RemoveMacroCommand.
 */

 /**
  * @brief success method to indicate that the macro was removed successfully.
  */
void RemoveMacroCommandCLI::success() {
    cout << "Macro removed successfully." << endl;
}

/**
 * @brief error method to display an error message.
 * 
 * @param message The error message to display.
 */
void RemoveMacroCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}

/**
 * @brief nothingToUndo method to indicate that there is nothing to undo.
 */
void RemoveMacroCommandCLI::nothingToUndo() {
    cout << "Nothing to undo." << endl;
}

/**
 * @brief successUndo method to indicate that the undo operation was successful.
 */
void RemoveMacroCommandCLI::successUndo() {
    cout << "Undo remove macro successful." << endl;
}

/**
 * @brief getMacroName method to prompt the user for the name of the macro to remove.
 * 
 * @return string The name of the macro to remove.
 */
string RemoveMacroCommandCLI::getMacroName() {
    cout << "Enter the name of the macro to remove: ";
    string macroName;
    getline(cin, macroName);
    return macroName;
}