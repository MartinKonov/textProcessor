/**
 * @file ExitCommand.hpp
 * @author MK
 * @brief A command to exit the text processor application, handling document saving and cleanup.
 */

#pragma once
#include "Command.hpp"
#include "../CommandsCLI/ExitCommandCLI.hpp"
#include "../Document/DocumentRegister.hpp"

/**
 * @class ExitCommand
 * @brief A command to exit the text processor application, handling document saving and cleanup.
 */
class ExitCommand : public Command {
public:
    ExitCommand() = delete;
    ExitCommand(ExitCommandCLI* cli, DocumentRegister* documentRegister);
    ~ExitCommand() override = default;

    ExitCommand(const ExitCommand& other) = delete;
    ExitCommand& operator=(const ExitCommand& other) = delete;

    string getName() const override;
    void execute() override;
    void undo() override {};
    bool isUndoable() const override;
private:
    ExitCommandCLI* cli;
    DocumentRegister* documentRegister;
};
