/**
 * @file AddLineCommand.hpp
 * @author MK
 * @brief A command to add a line to the active document in the text processor application.
 * @version 0.1
 * @date 2025-05-29
 */
#pragma once
#include "Command.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../CommandsCLI/AddLineCommandCLI.hpp"


class AddLineCommand : public Command {

 public:
    AddLineCommand(AddLineCommandCLI* addLineCommandCLI);
    ~AddLineCommand() override;

    void execute() override;
    void undo() override;
    string getName() const override;

 private:
    AddLineCommandCLI* addLineCommandCLI;
    ActiveDocument* activeDocument;
};