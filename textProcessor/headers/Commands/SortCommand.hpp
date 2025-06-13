/**
 * @file SortCommand.hpp
 * @author MK
 * @brief A command to sort the lines in the active document or block in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../CommandsCLI/SortCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../Block/ActiveBlock.hpp"


/**
 * @brief A command to sort the lines in the active document or block in the text processor application.
 */
class SortCommand : public Command {

public:
    SortCommand() = delete;
    SortCommand(SortCommandCLI* cli, ActiveDocument* activeDocument, ActiveBlock* activeBlock);
    SortCommand(const SortCommand& other) = delete;
    SortCommand& operator=(const SortCommand& other) = delete;
    ~SortCommand() override;

    void execute() override;
    void undo() override;
    string getName() const override;

    private:
    SortCommandCLI* cli;
    ActiveDocument* activeDocument;
    ActiveBlock* activeBlock;
    Document* previousDocument;


};