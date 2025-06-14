/**
 * @file TrimLeadingCommand.hpp
 * @author MK
 * @brief A command class to trim leading whitespace from the active document.
 */
#pragma once
#include "Command.hpp"
#include "../CommandsCLI/TrimLeadingCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../Block/ActiveBlock.hpp"



/**
 * @class TrimLeadingCommand
 * @brief A command to trim leading whitespace from the active block in the active document or the whole active document.
 */
class TrimLeadingCommand : public Command {
public:
    TrimLeadingCommand() = delete;
    TrimLeadingCommand(TrimLeadingCommandCLI* cli, ActiveDocument* activeDocument, ActiveBlock* activeBlock);
    ~TrimLeadingCommand() override;
    TrimLeadingCommand(const TrimLeadingCommand& other) = delete;
    TrimLeadingCommand& operator=(const TrimLeadingCommand& other) = delete;

    string getName() const override;
    void execute() override;
    void undo() override;
    private:
    TrimLeadingCommandCLI* cli;
    ActiveDocument* activeDocument;
    ActiveBlock* activeBlock;
    Document* previousDocument;
};