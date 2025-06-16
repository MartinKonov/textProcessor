#include "../../headers/CommandsCLI/ShowDocumentNumLinesCommandCLI.hpp"

/**
 * @file ShowDocumentNumLinesCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the ShowDocumentNumLinesCommand.
 */

/**
 * @brief Displays the number of lines in the active document.
 * 
 * This method prints the number of lines in the active document to the console.
 * 
 * @param numLines The number of lines in the active document.
 */
void ShowDocumentNumLinesCommandCLI::showNumLines(int numLines) {
    cout << "Number of lines in the active document: " << numLines << endl;
}
