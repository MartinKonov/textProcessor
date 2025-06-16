#include "../../headers/Commands/RemoveMacroCommand.hpp"


/**
 * @file RemoveMacroCommand.cpp
 * @author MK
 * @brief A command to remove a macro in the text processor application.
 */
RemoveMacroCommand::RemoveMacroCommand(RemoveMacroCommandCLI* cli, MacroRegister* macroRegister) {
    this->cli = cli;
    this->macroRegister = macroRegister;
    this->previousMacro = nullptr;
}

/**
 * @brief Destructor for RemoveMacroCommand.
 * It deletes the previous macro to free up memory.
 */
RemoveMacroCommand::~RemoveMacroCommand() {
    delete previousMacro;
    previousMacro = nullptr;
}

/**
 * @brief Returns the name of the command.
 * 
 * @return string The name of the command.
 */
string RemoveMacroCommand::getName() const {
    return "Remove Macro";
}

/**
 * @brief Executes the command to remove a macro.
 * 
 * This method retrieves the macro name from the CLI, checks if the macro exists in the register,
 * and if it does, it removes the macro and stores it for potential undo functionality.
 */
void RemoveMacroCommand::execute() {
    string macroName = cli->getMacroName();

    if (!macroRegister->itemExists(macroName)) {
        cli->error("Macro does not exist.");
        return;
    }

    if(previousMacro) {
        delete previousMacro;
        previousMacro = nullptr;
    }
    previousMacro = new Macro(*macroRegister->getItem(macroName));
    
    try {
        macroRegister->removeItem(macroName);
    } catch (runtime_error& e) {
        cli->error(e.what());
        return;
    }

    cli->success();
}

/**
 * @brief Undoes the last executed command of removing a macro.
 * 
 * This method checks if there is a previous macro stored, and if so, it adds it back to the macro register.
 * If there is no previous macro, it shows an error message indicating that there is nothing to undo.
 */
void RemoveMacroCommand::undo() {
    if (!previousMacro) {
        cli->nothingToUndo();
        return;
    }

    try {
        macroRegister->addMacro(previousMacro->getName(), previousMacro->getCommandNames());
    } catch (runtime_error& e) {
        delete previousMacro;
        previousMacro = nullptr;
        cli->error(e.what());
        return;
    }

    cli->successUndo();
    delete previousMacro;
    previousMacro = nullptr;
}