#include "../../headers/CommandsCLI/ListLoadedDocumentsCommandCLI.hpp"

/**
 * @file ListLoadedDocumentsCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the ListLoadedDocumentsCommand.
 */

void ListLoadedDocumentsCommandCLI::success() {

}

/**
 * @brief Displays an error message.
 * 
 * @param message The error message to display (optional).
 */
void ListLoadedDocumentsCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}

/**
 * @brief Lists the loaded documents.
 * 
 * @param documentList A string containing the list of loaded documents.
 */
void ListLoadedDocumentsCommandCLI::listDocuments(string documentList) {
    if (documentList.empty()) {
        cout << "No documents loaded." << endl;
    } else {
        cout << documentList << endl;
    }
}