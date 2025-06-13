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

/**
 * @brief A class to register and manage commands in the text processor application.
 */
class CommandRegister {

 public:
   CommandRegister();
   ~CommandRegister();


    void registerCommand(Command* newCommand);
    void executeCommand(int index);
    string showAllCommands();
    void undo();

    int findIndex(string commandName);
 private:

    vector<Command*> allCommands;
    Stack<string> executedCommandNames;

    int findIndex(Command* command);
};