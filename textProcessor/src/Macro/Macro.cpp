#include "../headers/Macro/Macro.hpp"

/**
 * @brief Returns the names of the commands in the macro.
 * @return vector<string> A vector containing the names of the commands in the macro.
 */
vector<string> Macro::getCommandNames() {
    return commandNames;
}


/**
 * @brief Returns the name of the macro.
 * 
 * @return string The name of the macro.
 */
string Macro::getName() {
    return macroName;
}