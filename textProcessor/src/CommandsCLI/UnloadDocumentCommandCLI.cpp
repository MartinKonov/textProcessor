/**
 * @file UnloadDocumentCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the UnloadDocumentCommand.
 */
#include "../../headers/CommandsCLI/UnloadDocumentCommandCLI.hpp"


/**
 * @brief success method to indicate that the document has been unloaded successfully.
 */
void UnloadDocumentCommandCLI::success() {
    cout << "Document unloaded successfully" << endl;
}

/**
 * @brief Displays an error message if the document could not be unloaded.
 * 
 * @param message The error message to display (optional).
 */
void UnloadDocumentCommandCLI::error(string message) {
    cerr << message << endl;
}

/**
 * @brief Prompts the user to enter the path of the document to unload and returns it.
 * 
 * @return string The path of the document to unload.
 */
string UnloadDocumentCommandCLI::getDocPathToUnload() {
    string docPath;
    cout << "Enter the path of the document to unload: " << endl;
    getline(cin, docPath);

    return docPath;
}

/**
 * @brief Displays a message indicating that the document has changed since the last save.
 */
void UnloadDocumentCommandCLI::docHasChanged() {
    cout << "The document has changed since last save." << endl;
}

/**
 * @brief Prompts the user to save the document before unloading it.
 * 
 * @return bool True if the user wants to save the document, false otherwise.
 */
bool UnloadDocumentCommandCLI::saveQuery() {
    cout << "Do you want to save document before unload? Y/N" << endl;
    
    string answer;
    while(true){
        getline(cin, answer);
    
        if(answer == "Y")
        {
            return true;
        }
        else if (answer == "N"){
            return false;
        }
        else {
            cout << "Try again Y/N" << endl;
            answer.clear();
        }
    }
}
