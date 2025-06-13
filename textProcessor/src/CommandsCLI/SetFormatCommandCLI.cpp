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
  * @brief Displays an error message if the formatter could not be set.
  */
 void SetFormatCommandCLI::error(string message) {
        cerr << "Error: " << message << endl;
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