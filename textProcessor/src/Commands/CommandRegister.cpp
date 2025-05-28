#include "../../headers/Commands/CommandRegister.hpp"


void CommandRegister::registerCommand (Command* command) {
    if(findIndex(command)  > -1) {
        return;
    }
    allCommands.push_back(command);
}

int CommandRegister::findIndex (Command* command) {
    for (size_t i = 0; i < allCommands.size(); ++i) {
        if (allCommands[i]->getName() == command->getName()) {
            return i;
        }
    }
    return -1;
}

