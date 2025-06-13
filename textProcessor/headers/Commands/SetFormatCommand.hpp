/**
 * @file SetFormatCommand.hpp
 * @author MK
 * @brief A command to set the active formatter in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../Formatter/ActiveFormatter.hpp"
#include "../CommandsCLI/SetFormatCommandCLI.hpp"


/**
 * @class SetFormatCommand
 * @brief A command to set the active formatter in the text processor application.
 */
class SetFormatCommand : public Command {
    public:
        SetFormatCommand() = delete;
        SetFormatCommand(SetFormatCommandCLI* cli, ActiveFormatter* activeFormatter);
        ~SetFormatCommand() override = default;
        SetFormatCommand(const SetFormatCommand& other) = delete;
        SetFormatCommand& operator=(const SetFormatCommand& other) = delete;

        string getName() const override;
        void execute() override;
        void undo() override;

    private:
        SetFormatCommandCLI* cli;
        ActiveFormatter* activeFormatter;
        string previousFormatterType;
        int previousFormatPoint;
};