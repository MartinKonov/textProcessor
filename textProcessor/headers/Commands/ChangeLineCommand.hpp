/**
 * @file ChangeLineCommand.hpp
 * @author MK
 * @brief A command to change the content of a specific line in the active document.
 */
#pragma once
#include "Command.hpp"
#include "../CommandsCLI/ChangeLineCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"

/**
 * @class ChangeLineCommand
 * @brief A command to change the content of a specific line in the active document.
 */
class ChangeLineCommand : public Command {
 public:
    ChangeLineCommand() = delete;
    ChangeLineCommand(ChangeLineCommandCLI* cli, ActiveDocument* activeDocument);
    ~ChangeLineCommand() override;
    ChangeLineCommand(const ChangeLineCommand& other) = delete;
    ChangeLineCommand& operator=(const ChangeLineCommand& other) = delete;

    string getName() const override;
    void execute() override;
    void undo() override;

 private:
    ChangeLineCommandCLI* cli;
    ActiveDocument* activeDocument;
    Document* previousDocument;
};