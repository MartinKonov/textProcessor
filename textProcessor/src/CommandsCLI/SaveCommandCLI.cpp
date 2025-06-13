/**
 * @file SaveCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the SaveCommand.
 */
#include "../../headers/CommandsCLI/SaveCommandCLI.hpp"


/**
 * @brief Displays a success message when the document is saved successfully.
 */
void SaveCommandCLI::success(){
    cout << "Document saved successfully" << endl;
}

/**
 * @brief Displays a message indicating that there is nothing to save.
 * 
 * This method is called when the document has not changed since the last save operation.
 */
void SaveCommandCLI::documentHasntChanged(){
    cout << "Nothing to save." << endl;
}

/**
 * @brief Displays an error message if there was an error while saving the document.
 * 
 * @param message The error message to display (optional).
 */
void SaveCommandCLI::error(string message) {
    cerr << "SaveCommand::execute() " + message << endl;
}

