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

/**
 * @brief A class to register and manage commands in the text processor application.
 */
class CommandRegister {

 public:
   CommandRegister() = delete;
   CommandRegister(MacroRegister* macroRegister);
   ~CommandRegister();


    void registerCommand(Command* newCommand);
    void executeMacro();
    void executeCommand(int index);
    string showAllCommands();
    void undo();

    int findIndex(string commandName);
 private:

    vector<Command*> allCommands;
    Stack<string> executedCommandNames;
    MacroRegister* macroRegister;

    int findIndex(Command* command);
};