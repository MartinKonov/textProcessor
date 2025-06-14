#include "../../headers/CommandsCLI/ShowDocumentNameCommandCLI.hpp"


/**
 * @file ShowDocumentNameCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for showing the name of the active document.
 */

/**
 * @brief Displays the name of the active document.
 * 
 * This method prints the name of the active document to the console.
 * 
 * @param documentName The name of the active document to display.
 */
void ShowDocumentNameCommandCLI::showDocumentName(string documentName) {
    cout << "Active Document Name: " << documentName << endl;
}

/**
 * @brief Doesn't do anything in this case.
 */
void ShowDocumentNameCommandCLI::success() {
}

/**
 * @brief Displays an error message.
 * 
 * This method prints an error message to the console.
 * 
 * @param message The error message to display.
 */
void ShowDocumentNameCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}