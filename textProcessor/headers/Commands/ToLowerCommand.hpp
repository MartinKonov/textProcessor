/**
 * @file ToLowerCommand.hpp
 * @author MK
 * @brief A class to represent the ToLower command.
 */
#pragma once
#include "Command.hpp"
#include "../CommandsCLI/ToLowerCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../Block/ActiveBlock.hpp"


/**
 * @class ToLowerCommand
 * @brief A command to convert the content of the active document to lowercase.
 */
class ToLowerCommand : public Command {
public:
    ToLowerCommand() = delete;
    ToLowerCommand(ToLowerCommandCLI* cli, ActiveDocument* activeDocument, ActiveBlock* activeBlock);
    ~ToLowerCommand() override = default;
    ToLowerCommand(const ToLowerCommand& other) = delete;
    ToLowerCommand& operator=(const ToLowerCommand& other) = delete;

    string getName() const override;
    void execute() override;
    void undo() override;
private:
    ToLowerCommandCLI* cli;
    ActiveDocument* activeDocument;
    ActiveBlock* activeBlock;
    Document* previousDocumentState;
};