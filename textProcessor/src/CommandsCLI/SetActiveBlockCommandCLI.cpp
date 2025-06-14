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
 * @brief Displays an error message if there was an error while setting the active block.
 * 
 * @param message The error message to display (optional).
 */
void SetActiveBlockCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}

/**
 * @brief Displays an error message if there is no active document set before trying to set an active block.
 */
void SetActiveBlockCommandCLI::errorActiveDocument(){
    cerr << "Error: Please set active document before trying to set active block" << endl;
}

/**
 * @brief Displays the available blocks for the current active document.
 * 
 * @param blocksForDocSerialized The serialized string of blocks available for the current active document.
 */
void SetActiveBlockCommandCLI::showBlocksForActiveDoc(string blocksForDocSerialized) {
    cout << "Available blocks for current document:" << endl;
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

/**
 * @brief Displays a message indicating that there is nothing to undo.
 */
void SetActiveBlockCommandCLI::nothingToUndo() {
    cout << "Nothing has changed, nothing to undo." << endl;
}

/**
 * @brief Displays a message indicating that the active document has changed since the last active block.
 * 
 * This message suggests that the user should try to set a new active block with the blocks available for the current active document.
 */
void SetActiveBlockCommandCLI::documentHasChanged() {
    cout << "Active document has changed since last active block. Try to set a new active "
     << "block with the blocks available for the current active document." << endl;
}

/**
 * @brief Displays an error message if there was an error while undoing the last operation.
 * 
 * @param message The error message to display.
 */
void SetActiveBlockCommandCLI::errorUndo(string message) {
    cout << "Error undo: " << message << endl;
}