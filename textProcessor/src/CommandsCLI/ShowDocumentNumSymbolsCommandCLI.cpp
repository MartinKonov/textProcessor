#include "../../headers/CommandsCLI/ShowDocumentNumSymbolsCommandCLI.hpp"

/**
 * @file ShowDocumentNumSymbolsCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the ShowDocumentNumSymbolsCommand.
 */

/**
 * @brief Displays the number of symbols in the active document.
 * 
 * This method prints the number of symbols in the active document to the console.
 * 
 * @param numSymbols The number of symbols in the active document.
 */
void ShowDocumentNumSymbolsCommandCLI::showNumSymbols(int numSymbols) {
    cout << "Number of symbols in the active document: " << numSymbols << endl;
}
