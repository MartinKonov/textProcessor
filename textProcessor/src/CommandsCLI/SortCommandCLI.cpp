/**
 * @file SortCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the SortCommand.
 */
#include "../../headers/CommandsCLI/SortCommandCLI.hpp"

/**
 * @brief Displays a success message when the document is sorted successfully.
 */
void SortCommandCLI::success() {
    cout << "Document sorted successfully." << endl;
}

/**
 * @brief Displays an error message if the sorting operation fails.
 * 
 * @param message The error message to display (optional).
 */
void SortCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}

/**
 * @brief Displays a message indicating that there is nothing to undo.
 */
void SortCommandCLI::nothingToUndo() {
    cout << "Nothing has changed, nothing to undo." << endl;
}

/**
 * @brief Displays a success message when the sort operation is undone successfully.
 */
void SortCommandCLI::successUndo() {
    cout << "Sort operation undone successfully." << endl;
}