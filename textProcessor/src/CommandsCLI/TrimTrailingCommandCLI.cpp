#include "../../headers/CommandsCLI/TrimTrailingCommandCLI.hpp"

/**
 * @file TrimTrailingCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the TrimTrailingCommand.
 */

/**
 * @brief Displays a success message indicating that trailing whitespaces have been trimmed successfully.
 * 
 * This method is called after the trim trailing command has been executed successfully.
 */
void TrimTrailingCommandCLI::success() {
    cout << "Trailing whitespaces trimmed successfully." << endl;
}
