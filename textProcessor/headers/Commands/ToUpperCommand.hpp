/**
 * @file ToUpperCommand.hpp
 * @author MK
 * @brief A command to convert the content of the active document or block to uppercase in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../CommandsCLI/ToUpperCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../Block/ActiveBlock.hpp"


/**
 * @class ToUpperCommand
 * @brief A command to convert the content of the active document or block to uppercase in the text processor application.
 */
class ToUpperCommand : public Command {
public:
    ToUpperCommand() = delete;
    ToUpperCommand(ToUpperCommandCLI* cli, ActiveDocument* activeDocument, ActiveBlock* activeBlock);
    ToUpperCommand(const ToUpperCommand& other) = delete;
    ToUpperCommand& operator=(const ToUpperCommand& other) = delete;
    ~ToUpperCommand() override;

    void execute() override;
    void undo() override;
    string getName() const override;
private:
    ToUpperCommandCLI* cli;
    ActiveDocument* activeDocument;
    ActiveBlock* activeBlock;
    Document* previousDocument;
};