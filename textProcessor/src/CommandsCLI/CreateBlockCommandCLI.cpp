#include "../../headers/CommandsCLI/CreateBlockCommandCLI.hpp"

/**
 * @file CreateBlockCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the CreateBlockCommand.
 */
void CreateBlockCommandCLI::success(){
    cout << "Block created successfully" << endl;
}

/**
 * @brief Displays an error message.
 * 
 * @param message The error message to display (optional).
 */
void CreateBlockCommandCLI::errorNoActiveDocument() {
    cerr << "Error: No active document set, cannot create block with no active document" << endl;
}

/**
 * @brief Prompts the user to enter a block name and returns it.
 */
string CreateBlockCommandCLI::getBlockName() {
    string blockName;
    cout << "Enter block name:" << endl;
    getline(cin, blockName);
    return blockName;
}

/**
 * @brief Displays an error message if a block with the same name already exists.
 */
void CreateBlockCommandCLI::blockExists() {
    cout << "A block with this name already exists. Try again" << endl;
}

/**
 * @brief Prompts the user to enter the start line index for the block.
 * 
 * @return size_t The start line index entered by the user.
 */
size_t CreateBlockCommandCLI::getStartLineIndex() {
    string input;
    size_t startLineIndex = 0;

    cout << "Enter the block's start line index:" << endl;
    getline(cin, input);

    try {
        startLineIndex = stoul(input);
    } catch (const exception& e) {
        cerr << "Invalid number entered. Try again." << endl;
    }

    return startLineIndex;
}

/**
 * @brief Prompts the user to enter the end line index for the block.
 * 
 * @return size_t The end line index entered by the user.
 */
size_t CreateBlockCommandCLI::getEndLineIndex() {
    string input;
    size_t endLineIndex = 0;

    cout << "Enter the block's end line index:" << endl;
    getline(cin, input);

    try {
        endLineIndex = stoul(input);
    } catch (const exception& e) {
        cerr << "Invalid number entered. Try again." << endl;
    }

    return endLineIndex;
}

/**
 * @brief Displays an error message when an undo operation fails.
 * 
 * @param message The error message to display.
 */
void CreateBlockCommandCLI::error(string message) {
    cerr << "Error undo: " << message << endl;
}

/**
 * @brief Displays a success message after successfully undoing the create block command.
 */
void CreateBlockCommandCLI::successUndo() {
    cout << "Create block undo successful" << endl;
}