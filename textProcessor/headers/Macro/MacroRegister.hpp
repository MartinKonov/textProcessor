/**
 * @file MacroRegister.hpp
 * @author MK
 * @brief A class to register and manage macros in the text processor application.
 */
#pragma once

#include "MacroParser.hpp"
#include "Macro.hpp"
#include "../GenericDataClasses/DataRegister.hpp"

// add macro will ask for list of commands from commandManager and only add macro through the regiset and with strings
// execute macro will ask for macro name which will come from getMacro. Then for each command name, it will call commandManager->executeCommand(commandName)

/**
 * @brief A class to register and manage macros in the text processor application.
 */
class MacroRegister : public DataRegister<MacroRegister, Macro, MacroParser> {
 public:
    static MacroRegister* getInstance();
    static void destroyInstance();

    void addMacro(string macroName, const vector<string> commandNames);

   static string getType();

   static string getItemName(Macro* macro);
 private:
    MacroRegister();
    ~MacroRegister();
    MacroRegister(const MacroRegister&) = delete;
    MacroRegister& operator=(const MacroRegister&) = delete;

    static MacroRegister* instance;
};