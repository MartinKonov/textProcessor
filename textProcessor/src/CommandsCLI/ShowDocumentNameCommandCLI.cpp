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
