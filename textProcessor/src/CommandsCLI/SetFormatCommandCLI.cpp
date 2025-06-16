#include "../../headers/CommandsCLI/SetFormatCommandCLI.hpp"

/**
 * @file SetFormatCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the SetFormatCommand.
 */

 /**
  * @brief Displays a success message when the formatter is set successfully.
  */
 void SetFormatCommandCLI::success() {
        cout << "Formatter set successfully." << endl;
 }

 /**
  * @brief Gets the format point from the user.
  * 
  * This method prompts the user to enter a positive integer for the format point.
  * If the input is invalid, it throws an exception.
  * 
  * @return int The format point entered by the user.
  */
int SetFormatCommandCLI::getFormatPoint() {
    cout << "Enter format point (positive integer): ";
    string input;
    getline(cin, input);
    try {
        int fp = std::stoi(input);
        if (fp <= 0) throw std::invalid_argument("Negative format point is not allowed.");
        return fp;
    } catch (...) {
        throw std::runtime_error("Invalid format point");
    }
}

 /**
  * @brief Gets the formatter type from the user.
  */
 string SetFormatCommandCLI::getFormatterType(string currentFormatterType) {
        cout << "Current formatter type: " << currentFormatterType << endl;
        cout << "Enter new formatter type (CenterFormatter, DirectFormatter, WrapFormatter):" << endl;
        string formatterType;
        getline(cin, formatterType);

        return formatterType;
 }

 void SetFormatCommandCLI::successUndo() {
        cout << "Formatter change undone successfully." << endl;
 }