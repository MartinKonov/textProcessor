#pragma once

#include "MacroParser.hpp"
#include "Macro.hpp"

// add macro will ask for list of commands from commandManager and only add macro through the regiset and with strings
// execute macro will ask for macro name which will come from getMacro. Then for each command name, it will call commandManager->executeCommand(commandName)

class MacroRegister {
 public:
    static MacroRegister* getInstance();
    static void destroyInstance();

    void addMacro(const string& macroName, const vector<string>& commandNames);
    void removeMacro(const string& macroName);
    Macro* getMacro(const string& macroName);
    vector<Macro*> getAllMacros();
    // string showMacros()

 private:
    MacroRegister();
    ~MacroRegister();

    static MacroRegister* instance;
    MacroParser* macroParser;
    vector<Macro*> macros;

    int findIndex(const string& macroName) const;
};