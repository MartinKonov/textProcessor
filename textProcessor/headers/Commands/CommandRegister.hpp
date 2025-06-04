/**
 * @file CommandRegister.hpp
 * @author MK
 * @brief A singleton class to manage a collection of commands in the text processor application.
 * @version 0.1
 * @date 2025-05-26
 */

#pragma once
#include "Command.hpp"
#include "../Utils/Stack.hpp"

class CommandRegister {

 public:
   CommandRegister();
   ~CommandRegister();


    void registerCommand(Command* newCommand);
    void executeCommand(int index);
    string showAllCommands();
    void undo();

 private:

    vector<Command*> allCommands;
    Stack<string> executedCommandNames;

    int findIndex(Command* command);
    int findIndex(string commandName);
};