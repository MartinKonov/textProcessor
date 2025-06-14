/**
 * @file ShowDocumentName.hpp
 * @author MK
 * @brief A command to show the name of the active document in the text processor application.
 */

#pragma once
#include "Command.hpp"
#include "../CommandsCLI/ShowDocumentNameCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"
/**
 * @class ShowDocumentNameCommand
 * @brief A command to show the name of the active document in the text processor application.
 */
class ShowDocumentNameCommand : public Command {
public:
    ShowDocumentNameCommand() = delete;
    ShowDocumentNameCommand(ShowDocumentNameCommandCLI* cli, ActiveDocument* activeDocument);
    ~ShowDocumentNameCommand() override = default;

    string getName() const override;
    void execute() override;
    void undo() override;
    bool isUndoable() const override;
private:
    ShowDocumentNameCommandCLI* cli;
    ActiveDocument* activeDocument;
};