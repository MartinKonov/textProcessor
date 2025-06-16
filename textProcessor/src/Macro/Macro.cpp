#include "../headers/Macro/Macro.hpp"

Macro::~Macro() {
    this->commandNames.clear();
}

/**
 * @brief copy constructor for the Macro class.
 * Transfers ownership of resources from the source object to the new object.
 * 
 * @param other The source Macro object to copy from.
 */
Macro::Macro(const Macro& other) {
    this->macroName = other.macroName;
    for(string commandNames : other.commandNames) {
        this->commandNames.push_back(commandNames);
    }
}

/**
 * @brief copy assignment operator for the Macro class.
 * Transfers ownership of resources from the source object to the current object.
 * 
 * @param other The source Macro object to copy from.
 * @return Macro& Reference to the current object after the copy assignment.
 */
Macro& Macro::operator=(const Macro& other) {
    if (this != &other) {
        this->macroName = other.macroName;
        this->commandNames.clear();
        for (string commandName : other.commandNames) {
            this->commandNames.push_back(commandName);
        }
    }
    return *this;
}

/**
 * @brief Move constructor for the Macro class.
 * Transfers ownership of resources from the source object to the new object.
 * 
 * @param other The source Macro object to move from.
 */
Macro::Macro(Macro&& other) noexcept
    : commandNames(move(other.commandNames)), macroName(move(other.macroName)) {
    other.commandNames.clear();
}

/**
 * @brief Move assignment operator for the Macro class.
 * @param other The source Macro object to move from.
 */
Macro& Macro::operator=(Macro&& other) noexcept {
    if (this != &other) {
        this->commandNames = move(other.commandNames);
        this->macroName = move(other.macroName);
        other.commandNames.clear();
    }
    return *this;
}

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