/**
 * @file RemoveBlockCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the RemoveBlockCommand.
 */
#include "../../headers/CommandsCLI/RemoveBlockCommandCLI.hpp"

/**
 * @brief Displays a success message when the block is removed.
 */
void RemoveBlockCommandCLI::success() {
    cout << "Block removed successfully" << endl;
}

/**
 * @brief Displays an error message if the block could not be removed.
 * 
 * @param message The error message to display (optional).
 */
void RemoveBlockCommandCLI::error(string message) {
    cerr << "Error removing block: " << message << endl;
}

/**
 * @brief Prompts the user to enter the name of the block to be removed and returns it.
 * 
 * @return string The name of the block to be removed.
 */
string RemoveBlockCommandCLI::getBlockName() {
    string blockName;
    cout << "Enter the name of the block to be removed:" << endl;
    getline(cin, blockName);
    return blockName;
}

/**
 * @brief Displays an error message if the block with the specified name does not exist.
 */
void RemoveBlockCommandCLI::blockDoesntExist() {
    cerr << "A block with this name doesn't exist." << endl;
}

/**
 * @brief Displays an error message if the block could not be removed because no previous state was found.
 */
void RemoveBlockCommandCLI::removedBlockError() {
    cerr << "Can't undo, no previous state of block found" << endl;
}

/**
 * @brief Displays an error message if there was an error while undoing the remove block operation.
 * 
 * @param message The error message to display.
 */
void RemoveBlockCommandCLI::errorUndo(string message) {
    cerr << "Error durring undo remove block: " << message << endl;
}