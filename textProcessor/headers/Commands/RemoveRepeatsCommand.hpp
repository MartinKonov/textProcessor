/**
 * @file RemoveRepeatsCommand.hpp
 * @author MK
 * @brief A command to remove repeated lines in the active document or block in the text processor application.
 */
#pragma once
#include "Command.hpp"

#include "../CommandsCLI/RemoveRepeatsCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../Block/ActiveBlock.hpp"


/**
 * @class RemoveRepeatsCommand
 * @brief A command to remove repeated lines in the active document or block in the text processor application.
 */
class RemoveRepeatsCommand : public Command {
public:
    RemoveRepeatsCommand() = delete;
    RemoveRepeatsCommand(RemoveRepeatsCommandCLI* cli, ActiveDocument* activeDocument, ActiveBlock* activeBlock);
    RemoveRepeatsCommand(const RemoveRepeatsCommand& other) = delete;
    RemoveRepeatsCommand& operator=(const RemoveRepeatsCommand& other) = delete;
    ~RemoveRepeatsCommand() override;

    string getName() const override;
    void execute() override;
    void undo() override;
private:
    RemoveRepeatsCommandCLI* cli;
    ActiveDocument* activeDocument;
    ActiveBlock* activeBlock;
    Document* previousDocument;
};