/**
 * @file SetActiveBlockCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the SetActiveBlockCommand.
 */
#include "../../headers/CommandsCLI/SetActiveBlockCommandCLI.hpp"


/**
 * @brief Displays a success message when the active block is set successfully.
 */
void SetActiveBlockCommandCLI::success() {
    cout << "Active block set successfully" << endl;
}

/**
 * @brief Displays the available blocks for the current active document.
 * 
 * @param blocksForDocSerialized The serialized string of blocks available for the current active document.
 */
void SetActiveBlockCommandCLI::showBlocksForActiveDoc(string blocksForDocSerialized) {
    cout << blocksForDocSerialized << endl;
}

/**
 * @brief Prompts the user to enter the name of the desired new active block and returns it.
 * 
 * @return string The name of the new active block.
 */
string SetActiveBlockCommandCLI::getNewActiveBlockName() {
    cout << "Enter the name of the desired new active block:" << endl;
    string blockName;
    getline(cin, blockName);
    return blockName;
}
