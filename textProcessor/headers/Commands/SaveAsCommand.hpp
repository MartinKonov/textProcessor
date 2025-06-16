/**
 * @file SaveAsCommand.hpp
 * @author MK
 * @brief A command to save the active document under a new name in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../CommandsCLI/SaveAsCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../Document/DocumentRegister.hpp"

/**
 * @brief A command to save the active document under a new name in the text processor application.
 */
class SaveAsCommand: public Command {
public:
    SaveAsCommand() = delete;
    SaveAsCommand(ActiveDocument* activeDocument, SaveAsCommandCLI* cli, DocumentRegister* documentRegister);
    SaveAsCommand(const SaveAsCommand& other) = delete;
    SaveAsCommand& operator=(const SaveAsCommand &other) = delete;
    ~SaveAsCommand() override = default;

    string getName() const override;
    void execute() override;
    void undo() override {};
    bool isUndoable() const override;

private:
    ActiveDocument* activeDocument;
    DocumentRegister* documentRegister;
    SaveAsCommandCLI* cli;
};