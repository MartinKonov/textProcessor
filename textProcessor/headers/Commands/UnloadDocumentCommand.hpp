#pragma once
#include "Command.hpp"
#include "../CommandsCLI/UnloadDocumentCommandCLI.hpp"
#include "../Document/DocumentRegister.hpp"



class UnloadDocumentCommand : public Command {

public:
    UnloadDocumentCommand() = delete;
    UnloadDocumentCommand(UnloadDocumentCommandCLI* unloadDocumentCommandCLI, DocumentRegister* documentRegister);
    UnloadDocumentCommand(UnloadDocumentCommand& other) = delete;
    UnloadDocumentCommand& operator=(UnloadDocumentCommand& other) = delete;
    ~UnloadDocumentCommand() override = default;

    string getName() const override;
    void execute() override;
    void undo() override;

private:
    void handleDocHasChanged(Document* document);

    UnloadDocumentCommandCLI* unloadDocumentCommandCLI;
    DocumentRegister* documentRegister;
};