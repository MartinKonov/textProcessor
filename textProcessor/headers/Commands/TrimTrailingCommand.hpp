#pragma once
#include "Command.hpp"
#include "../CommandsCLI/TrimTrailingCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../Block/ActiveBlock.hpp"


/**
 * @class TrimTrailingCommand
 * @brief A command to trim trailing whitespace from the active block in the active document or the whole active document.
 */
class TrimTrailingCommand : public Command {
public:
    TrimTrailingCommand() = delete;
    TrimTrailingCommand(TrimTrailingCommandCLI* cli, ActiveDocument* activeDocument, ActiveBlock* activeBlock);
    ~TrimTrailingCommand() override;
    TrimTrailingCommand(const TrimTrailingCommand& other) = delete;
    TrimTrailingCommand& operator=(const TrimTrailingCommand &other) = delete;

    string getName() const override;
    void execute() override;
    void undo() override;
private:
    TrimTrailingCommandCLI* cli;
    ActiveDocument* activeDocument;
    ActiveBlock* activeBlock;
    Document* previousDocument;
};