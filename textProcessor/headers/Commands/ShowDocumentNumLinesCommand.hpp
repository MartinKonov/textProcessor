/**
 * @file ShowDocumentNumLinesCommand.hpp
 * @author MK
 * @brief A command to show the number of lines in the active document in the text processor application.
 */

#pragma once
#include "Command.hpp"
#include "../CommandsCLI/ShowDocumentNumLinesCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"

/**
 * @class ShowDocumentNumLinesCommand
 * @brief A command to show the number of lines in the active document in the text processor application.
 */
class ShowDocumentNumLinesCommand : public Command {
public:
    ShowDocumentNumLinesCommand() = delete;
    ShowDocumentNumLinesCommand(ShowDocumentNumLinesCommandCLI* cli, ActiveDocument* activeDocument);
    ~ShowDocumentNumLinesCommand() override = default;

    string getName() const override;
    void execute() override;
    void undo() override {};
    bool isUndoable() const override;
private:
    ShowDocumentNumLinesCommandCLI* cli;
    ActiveDocument* activeDocument;
};