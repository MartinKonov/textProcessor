#include "../../headers/Commands/CommandRegister.hpp"
#include <iostream>

CommandRegister::~CommandRegister()
{
    allCommands.clear();
}

CommandRegister::CommandRegister(MacroRegister* macroRegister) {
    this->macroRegister = macroRegister;
}

/**
 * @brief Registers a command in the command register.
 * If the command is already registered, it does nothing.
 * @param command Pointer to the command to be registered.
 */
void CommandRegister::registerCommand (Command* command) {
    if(findIndex(command)  > -1) {
        return;
    }
    allCommands.push_back(command);
}

/**
 * @brief Registers an exit command.
 * This command is used to handle the exit operation of the application.
 * @param exitCommand Pointer to the exit command to be registered.
 */
void CommandRegister::registerExitCommand(ExitCommand* exitCommand) {
    this->exitCommand = exitCommand;
}

/**
 * @brief Finds the index of a command by its name.
 * If the command is not found, it returns -1.
 * @param commandName The name of the command to find.
 */
int CommandRegister::findIndex(string commandName) {
    for (size_t i = 0; i < allCommands.size(); ++i) {
        if (allCommands[i]->getName() == commandName) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Finds the index of a command in the command register.
 * If the command is not found, it returns -1.
 * @param command Pointer to the command to find.
 */
int CommandRegister::findIndex(Command* command) {
    for (size_t i = 0; i < allCommands.size(); ++i) {
        if (allCommands[i] == command) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Executes a command by its index.
 * If the index is out of range, it throws an exception.
 * @param index The index of the command to execute.
 * @throws std::out_of_range if the index is invalid.
 * @throws std::runtime_error if the command execution fails.
 */
void CommandRegister::executeCommand(int index) {
    if (index < 0 || index >= allCommands.size()) {
        throw std::out_of_range("CommandRegister::executeCommand: Index out of range");
    }
    Command* command = allCommands[index];

    try{
        command->execute();
    } catch (const std::exception& e) {
        throw std::runtime_error("CommandRegister::executeCommand: " + string(e.what()));
    }

    if(command->isUndoable()){
        executedCommandNames.push(command->getName());
    }
}

/**
 * @brief Executes the exit command.
 * If the exit command is not registered, it throws an exception.
 * This command is used to handle the exit operation of the application.
 * @throws std::runtime_error if the exit command is not registered.
 */
void CommandRegister::executeExitCommand() {
    if (exitCommand == nullptr) {
        throw std::runtime_error("CommandRegister::executeExitCommand: Exit command not registered");
    }
    exitCommand->execute();
}


/**
 * @brief Executes a macro by its index.
 * If the index is out of range, it throws an exception.
 * It executes each command in the macro sequentially.
 * @param index The index of the macro to execute.
 * @throws std::out_of_range if the index is invalid.
 * @throws std::runtime_error if a command in the macro is not found or fails to execute.
 */
void CommandRegister::executeMacro(string macroName) {
    if (!macroRegister->itemExists(macroName)) {
        throw std::runtime_error("CommandRegister::executeMacro: Macro not found: " + macroName);
    }

    vector<Macro*> macros = macroRegister->getAll();
    int index = macroRegister->findIndex(macroName);

    Macro* macro = macros[index];
    vector<string> commandNames = macro->getCommandNames();
    
    for (const string& commandName : commandNames) {
        int commandIndex = findIndex(commandName);
        if (commandIndex == -1) {
            throw std::runtime_error("CommandRegister::executeMacro: Command not found: " + commandName);
        }
        executeCommand(commandIndex);
    }
}

/**
 * @brief Shows all registered macros.
 * @return A string containing the serialized representation of all macros.
 */
string CommandRegister::showAllMacros() {
    return macroRegister->showAll();
}

/**
 * @brief Shows all registered commands.
 * @return A string containing the names of all registered commands.
 */
string CommandRegister::showAllCommands() {
    string result;
    for(int i = 0; i < allCommands.size(); ++i) {
        result += std::to_string(i+1) + ". " + allCommands[i]->getName() + "\n";
    }
    return result;
}

/**
 * @brief Undoes the last executed command.
 * If there are no commands to undo, it throws an exception.
 * @throws std::runtime_error if there are no commands to undo or if the command is not found.
 */
void CommandRegister::undo() {
    if (executedCommandNames.empty()) {
        throw std::runtime_error("CommandRegister::undo: No commands to undo");
    }
    string commandName = executedCommandNames.top();
    executedCommandNames.pop();
    int index = findIndex(commandName);
    if (index == -1) {
        throw std::runtime_error("CommandRegister::undo: Command not found");
    }
    allCommands[index]->undo();
}


