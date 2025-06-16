
/**
 * @file ViewAllMacrosCommand.hpp
 * @author MK
 * @brief A command to view all macros in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../CommandsCLI/ViewAllMacrosCommandCLI.hpp"
#include "../Macro/MacroRegister.hpp"


/**
 * @class ViewAllMacrosCommand
 * @brief A command to view all macros in the text processor application.
 */
class ViewAllMacrosCommand : public Command {
public:
    ViewAllMacrosCommand(ViewAllMacrosCommandCLI* cli, MacroRegister* macroRegister);
    ~ViewAllMacrosCommand() override = default;

    string getName() const override;
    void execute() override;
    void undo() override {};
    bool isUndoable() const override;

private:
    ViewAllMacrosCommandCLI* cli;
    MacroRegister* macroRegister;
};