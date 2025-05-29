#include "../../headers/CommandsCLI/AddLineCommandCLI.hpp"

/**
 * @brief Gets the line input from the user.
 * 
 * This method prompts the user to enter a line and returns the input as a string.
 * 
 * @return string The line input from the user.
 */
string AddLineCommandCLI::getLineInput() {
    string line;
    cout << "Enter the line to add: ";
    getline(std::cin, line);
    return line;
}

/**
 * @brief Displays a success message after adding a line.
 * 
 * This method prints a success message to the console.
 */
void AddLineCommandCLI::success() {
    cout << "Line added successfully." << endl;
}

/**
 * @brief Displays an error message if there is an issue with adding a line.
 * 
 * This method prints an error message to the console. If a specific message is provided, it displays that; otherwise, it shows a generic error message.
 * 
 * @param message A pointer to a string containing the error message. If null, a generic error message is displayed.
 */
void AddLineCommandCLI::error(const string* message) {
    if (message) {
        cout << "Error: " << *message << endl;
    } else {
        cout << "An unknown error occurred." << endl;
    }
}