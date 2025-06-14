/**
 * @file InsertLineCommand.hpp
 * @author MK
 * @brief A command to insert a line into the active document in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../CommandsCLI/InsertLineCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"


/**
 * @class InsertLineCommand
 * @brief A command to insert a line into the active document in the text processor application.
 */
class InsertLineCommand : public Command {
public:
    InsertLineCommand() = delete;
    InsertLineCommand(InsertLineCommandCLI* cli, ActiveDocument* activeDocument);
    ~InsertLineCommand() override;
    InsertLineCommand(const InsertLineCommand& other) = delete;
    InsertLineCommand& operator=(const InsertLineCommand& other) = delete;

    string getName() const override;
    void execute() override;
    void undo() override;
private:
    InsertLineCommandCLI* cli;
    ActiveDocument* activeDocument;
    Document* previousDocument;
};