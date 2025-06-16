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
