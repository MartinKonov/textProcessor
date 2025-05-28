#pragma once
#include "Command.hpp"
#include "../Utils/Stack.hpp"

class CommandRegister {

    void registerCommand(Command* newCommand);
    void executeCommand(int index);
    string showAllCommands();
    void undo();

 private:
    
    vector<Command*> allCommands;
    Stack<string> executedCommandNames;

    int findIndex(Command* command);
};