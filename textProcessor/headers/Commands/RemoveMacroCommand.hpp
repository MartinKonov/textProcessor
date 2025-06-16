/**
 * @file RemoveMacroCommand.hpp
 * @author MK
 * @brief A command to remove a macro in the text processor application.
 */

#pragma once
#include "Command.hpp"
#include "../CommandsCLI/RemoveMacroCommandCLI.hpp"
#include "../Macro/MacroRegister.hpp"



/**
 * @class RemoveMacroCommand
 * @brief A command to remove a macro in the text processor application.
 */
class RemoveMacroCommand : public Command {
public:
    RemoveMacroCommand() = delete;
    RemoveMacroCommand(RemoveMacroCommandCLI* cli, MacroRegister* macroRegister);
    ~RemoveMacroCommand() override;
    RemoveMacroCommand(const RemoveMacroCommand& other) = delete;
    RemoveMacroCommand& operator=(const RemoveMacroCommand& other) = delete;

    string getName() const override;
    void execute() override;
    void undo() override;
private:
    RemoveMacroCommandCLI* cli;
    MacroRegister* macroRegister;
    Macro* previousMacro;
};

