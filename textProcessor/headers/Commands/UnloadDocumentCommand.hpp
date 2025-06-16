/**
 * @file UnloadDocumentCommand.hpp
 * @author MK
 * @brief A command to unload a document in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../CommandsCLI/UnloadDocumentCommandCLI.hpp"
#include "../Document/DocumentRegister.hpp"
#include "../Document/ActiveDocument.hpp"


/**
 * @brief A command to unload a document in the text processor application.
 */
class UnloadDocumentCommand : public Command {

public:
    UnloadDocumentCommand() = delete;
    UnloadDocumentCommand(UnloadDocumentCommandCLI* cli, DocumentRegister* documentRegister, ActiveDocument* activeDocument);
    UnloadDocumentCommand(UnloadDocumentCommand& other) = delete;
    UnloadDocumentCommand& operator=(UnloadDocumentCommand& other) = delete;
    ~UnloadDocumentCommand() override = default;

    string getName() const override;
    void execute() override;
    void undo() override {};
    bool isUndoable() const override;

private:
    void handleDocHasChanged(Document* document);

    UnloadDocumentCommandCLI* cli;
    DocumentRegister* documentRegister;
    ActiveDocument* activeDocument;
};