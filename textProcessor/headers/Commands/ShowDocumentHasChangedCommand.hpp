/**
 * @file ShowDocumentHasChangedCommand.hpp
 * @author MK
 * @brief A command to show whether the active document has changed.
 */

#pragma once
#include "Command.hpp"
#include "../CommandsCLI/ShowDocumentHasChangedCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"
/**
 * @class ShowDocumentHasChangedCommand
 * @brief A command to show whether the active document has changed.
 */

class ShowDocumentHasChangedCommand : public Command {
public:
    ShowDocumentHasChangedCommand() = delete;
    ShowDocumentHasChangedCommand(ShowDocumentHasChangedCommandCLI* cli, ActiveDocument* activeDocument);
    ~ShowDocumentHasChangedCommand() override = default;

    ShowDocumentHasChangedCommand(const ShowDocumentHasChangedCommand& other) = delete;
    ShowDocumentHasChangedCommand& operator=(const ShowDocumentHasChangedCommand& other) = delete;

    string getName() const override;
    void execute() override;
    void undo() override {};
    bool isUndoable() const override;
private:
    ShowDocumentHasChangedCommandCLI* cli;
    ActiveDocument* activeDocument;
};