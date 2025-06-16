#include "../../headers/CommandsCLI/AddMacroCommandCLI.hpp"

/**
 * @file AddMacroCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the AddMacroCommand.
 */


/**
 * @brief Displays success message when a macro is added successfully.
 */
void AddMacroCommandCLI::success() {
    cout << "Macro added successfully." << endl;
}

/**
 * @brief Prompts the user to enter the name of the macro.
 * 
 * @return string The name of the macro entered by the user.
 */
string AddMacroCommandCLI::getMacroName() {
    string macroName;
    cout << "Enter the name of the macro: ";
    getline(cin, macroName);
    return macroName;
}

/**
 * @brief Prompts the user to enter the names of the commands that will be part of the macro.
 * 
 * @return vector<string> A vector containing the names of the commands.
 */
vector<string> AddMacroCommandCLI::getCommandNames() {
    vector<string> commandNames;
    string commandName;
    cout << "Enter the names of the commands (type 'done' when finished):" << endl;
    
    while (true) {
        cout << "> ";
        getline(cin, commandName);
        if (commandName == "done") {
            break;
        }
        commandNames.push_back(commandName);
    }
    
    return commandNames;
}

/**
 * @brief Displays a success message when the undo operation for adding a macro is successful.
 */
void AddMacroCommandCLI::successUndo() {
    cout << "Undo add macro successful." << endl;
}