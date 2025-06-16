/**
 * @file AddMacroCommand.hpp
 * @author MK
 * @brief A command to add a macro in the text processor application.
 */

#pragma once
#include "Command.hpp"
#include "../CommandsCLI/AddMacroCommandCLI.hpp"
#include "../Macro/MacroRegister.hpp"


/**
 * @class AddMacroCommand
 * @brief A command to add a macro in the text processor application.
 */
class AddMacroCommand : public Command {
public:
    AddMacroCommand() = delete;
    AddMacroCommand(AddMacroCommandCLI* cli, MacroRegister* macroRegister);
    ~AddMacroCommand() override = default;

    string getName() const override;
    void execute() override;
    void undo() override;
private:
    AddMacroCommandCLI* cli;
    MacroRegister* macroRegister;
    string previousMacroName;
};
