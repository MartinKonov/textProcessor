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

/**
 * @brief A command to add a line to the active document in the text processor application.
 */
class AddLineCommand : public Command {

 public:
    AddLineCommand() = delete;
    AddLineCommand(AddLineCommandCLI* cli, ActiveDocument* activeDocument);
    ~AddLineCommand() override;
    AddLineCommand(const AddLineCommand& other) = delete;
    AddLineCommand& operator=(const AddLineCommand& other) = delete;

    void execute() override;
    void undo() override;
    string getName() const override;

 private:
   void setDocBeforeExecution(Document* currentActiveDocument);

    AddLineCommandCLI* cli;
    ActiveDocument* activeDocument;
    Document* docBeforeExecution;
};