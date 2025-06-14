#include "../../headers/CommandsCLI/LoadDocumentCommandCLI.hpp"

/**
 * @file LoadDocumentCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the LoadDocumentCommand.
 */
void LoadDocumentCommandCLI::success() {
    cout << "Document loaded successfully" << endl; 
}

/**
 * @brief Prompts the user to enter the document full file path and returns it.
 * 
 * @return string The full file path of the document.
 */
string LoadDocumentCommandCLI::getDocFilePath() {
    string docFilePath;

    cout << "Enter the document full file path: " << endl;
    getline(cin, docFilePath);

    return docFilePath;
}

/**
 * @brief Displays an error message if the document could not be loaded.
 * 
 * @param message The error message to display (optional).
 */
void LoadDocumentCommandCLI::error(string message) {
    cerr << "Error: " << message << endl;
}
