/**
 * @file ViewAllBlocksCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the ViewAllBlocksCommand.
 */
#include "../../headers/CommandsCLI/ViewAllBlocksCommandCLI.hpp"

/**
 * @brief Displays a success message indicating that the blocks have been viewed successfully.
 */
void ViewAllBlocksCommandCLI::success() {
}

/**
 * @brief Displays an error message if there was an issue viewing the blocks.
 * 
 * @param message The error message to display (optional).
 */
void ViewAllBlocksCommandCLI::error(string message) {
    cerr << "Error viewing blocks: " << message << endl;
}

/**
 * @brief Displays the available blocks for the active document.
 * 
 * @param blocksForDocSerialized The serialized string of blocks for the active document.
 */
void ViewAllBlocksCommandCLI::showBlocksForActiveDoc(string blocksForDocSerialized) {
    cout << "Available blocks for active document:" << endl;
    cout << blocksForDocSerialized << endl;
}

