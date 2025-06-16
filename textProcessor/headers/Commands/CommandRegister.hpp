/**
 * @file CommandRegister.hpp
 * @author MK
 * @brief A class to register and manage commands in the text processor application.
 * @version 0.1
 * @date 2025-05-26
 */

#pragma once
#include "Command.hpp"
#include "../Utils/Stack.hpp"
#include "../Macro/MacroRegister.hpp"
#include "ExitCommand.hpp"

/**
 * @brief A class to register and manage commands in the text processor application.
 */
class CommandRegister {

 public:
   CommandRegister() = delete;
   CommandRegister(MacroRegister* macroRegister);
   ~CommandRegister();


    void registerCommand(Command* newCommand);
    void registerExitCommand(ExitCommand* exitCommand);
    void executeMacro(string macroName);
    void executeCommand(int index);
    void executeExitCommand();
    string showAllCommands();
    string showAllMacros();
    void undo();

    int findIndex(string commandName);
 private:

    vector<Command*> allCommands;
    Stack<string> executedCommandNames;
    MacroRegister* macroRegister;
    ExitCommand* exitCommand;

    int findIndex(Command* command);
};