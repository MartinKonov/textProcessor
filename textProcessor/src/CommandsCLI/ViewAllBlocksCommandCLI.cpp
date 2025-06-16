/**
 * @file ViewAllBlocksCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the ViewAllBlocksCommand.
 */
#include "../../headers/CommandsCLI/ViewAllBlocksCommandCLI.hpp"

/**
 * @brief Displays the available blocks for the active document.
 * 
 * @param blocksForDocSerialized The serialized string of blocks for the active document.
 */
void ViewAllBlocksCommandCLI::showBlocksForActiveDoc(string blocksForDocSerialized) {
    cout << "Available blocks for active document:" << endl;
    cout << blocksForDocSerialized << endl;
}

