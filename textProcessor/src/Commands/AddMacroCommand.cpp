#include "../../headers/Commands/AddMacroCommand.hpp"
/**
 * @file AddMacroCommand.cpp
 * @author MK
 * @brief A command to add a macro in the text processor application.
 */
AddMacroCommand::AddMacroCommand(AddMacroCommandCLI* cli, MacroRegister* macroRegister) {
    this->cli = cli;
    this->macroRegister = macroRegister;
    this->previousMacroName = "";
}

/**
 * @brief gets the name of the command.
 */
string AddMacroCommand::getName() const {
    return ADD_MACRO_COMMAND_NAME;
}

/**
 * @brief Executes the command to add a macro.
 * 
 * This method retrieves the macro name and command names from the CLI, checks if the macro already exists,
 * and if not, adds the macro to the MacroRegister. It also stores the previous macro name for potential undo functionality.
 */
void AddMacroCommand::execute() {
    string macroName = cli->getMacroName();
    vector<string> commandNames = cli->getCommandNames();

    if (macroRegister->itemExists(macroName)) {
        cli->error(ERROR_MACRO_ALREADY_EXISTS);
        return;
    }

    previousMacroName = macroName;
    try{
        macroRegister->addMacro(macroName, commandNames);
    } catch (const runtime_error& e) {
        cli->error(ERROR_ADDING_MACRO + string(e.what()));
        return;
    }
    cli->success();
}

/**
 * @brief Undoes the last executed command of adding a macro.
 * 
 * This method removes the macro with the previous name from the MacroRegister.
 * If the macro does not exist, it shows an error message.
 */
void AddMacroCommand::undo() {
    if (previousMacroName.empty()) {
        cli->error(ERROR_UNDO);
        return;
    }

    if (!macroRegister->itemExists(previousMacroName)) {
        cli->error(ERROR_UNDO);
        return;
    }

    try{
        macroRegister->removeItem(previousMacroName);
    } catch (const std::runtime_error& e) {
        cli->error(ERROR_REMOVING_MACRO + string(e.what()));
        return;
    }
    cli->successUndo();
    previousMacroName.clear();
}
