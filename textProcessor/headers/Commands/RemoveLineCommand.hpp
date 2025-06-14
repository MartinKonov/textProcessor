/**
 * @file RemoveLineCommand.hpp
 * @author MK
 * @brief A command to remove a line from the active document in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../CommandsCLI/RemoveLineCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"



/**
 * @class RemoveLineCommand
 * @brief A command to remove a line from the active document in the text processor application.
 */
class RemoveLineCommand : public Command {
    public:
        RemoveLineCommand() = delete;
        RemoveLineCommand(RemoveLineCommandCLI* cli, ActiveDocument* activeDocument);
        ~RemoveLineCommand() override;
        RemoveLineCommand(const RemoveLineCommand& other) = delete;
        RemoveLineCommand& operator=(const RemoveLineCommand& other) = delete;

        string getName() const override;
        void execute() override;
        void undo() override;
    private:
        RemoveLineCommandCLI* cli;
        ActiveDocument* activeDocument;
        Document* previousDocument;
};