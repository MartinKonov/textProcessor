#include "../../headers/Commands/ViewAllMacrosCommand.hpp"

/**
 * @file ViewAllMacrosCommand.cpp
 * @author MK
 * @brief A command to view all macros in the text processor application.
 */
ViewAllMacrosCommand::ViewAllMacrosCommand(ViewAllMacrosCommandCLI* cli, MacroRegister* macroRegister) {
    this->cli = cli;
    this->macroRegister = macroRegister;
}


/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string ViewAllMacrosCommand::getName() const {
    return VIEW_ALL_MACROS_COMMAND_NAME;
}


/**
 * @brief Executes the command to view all macros.
 * 
 * This method retrieves all macros from the macro register and displays them using the CLI.
 * If there are no macros available, it shows an error message.
 */
void ViewAllMacrosCommand::execute() {

    string serializedMacros = macroRegister->toString();

    if (serializedMacros.empty()) {
        cli->error(ERROR_NO_MACROS_FOUND);
        return;
    }

    cli->showCurrentMacros(serializedMacros);
}

/**
 * @brief This command is not undoable.
 * 
 * @return true if the command is undoable, false otherwise.
 */
bool ViewAllMacrosCommand::isUndoable() const {
    return false;
}