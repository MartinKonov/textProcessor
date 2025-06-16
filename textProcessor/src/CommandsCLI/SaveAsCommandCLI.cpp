/**
 * @file SaveAsCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the SaveAsCommand.
 */
#include "../../headers/CommandsCLI/SaveAsCommandCLI.hpp"

/**
 * @brief Displays a success message when the document is saved successfully.
 */
void SaveAsCommandCLI::success(){
    cout << "Document saved successfully" << endl;
}

/**
 * @brief Prompts the user to enter a new document name and returns it.
 * 
 * @return string The new document name entered by the user.
 */
string SaveAsCommandCLI::getNewDocName() {
    cout << "Enter the new document name" << endl;
    string newDocName;
    getline(cin, newDocName);
    return newDocName;
}
