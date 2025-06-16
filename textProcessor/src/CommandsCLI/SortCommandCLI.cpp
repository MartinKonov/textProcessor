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
 * @brief Displays a success message when the sort operation is undone successfully.
 */
void SortCommandCLI::successUndo() {
    cout << "Sort operation undone successfully." << endl;
}