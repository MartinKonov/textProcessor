/**
 * @file ScrambleCommand.hpp
 * @author MK
 * @brief A command to scramble the contents of the active document in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../CommandsCLI/ScrambleCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../Block/ActiveBlock.hpp"


/**
 * @class ScrambleCommand
 * @brief A command to scramble the contents of the active document in the text processor application.
 */
class ScrambleCommand : public Command {
public:
    ScrambleCommand() = delete;
    ScrambleCommand(ScrambleCommandCLI* cli, ActiveDocument* activeDocument, ActiveBlock* activeBlock);
    ~ScrambleCommand() override = default;
    ScrambleCommand(const ScrambleCommand& other) = delete;
    ScrambleCommand& operator=(const ScrambleCommand& other) = delete;

    string getName() const override;
    void execute() override;
    void undo() override;
private:
    ScrambleCommandCLI* cli;
    ActiveDocument* activeDocument;
    ActiveBlock* activeBlock;
    Document* previousDocument;
};

