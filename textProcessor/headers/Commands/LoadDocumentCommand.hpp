#pragma once
#include "Command.hpp"
#include "../CommandsCLI/LoadDocumentCommandCLI.hpp"
#include "../Document/DocumentRegister.hpp"




class LoadDocumentCommand : public Command {

public:
    LoadDocumentCommand() = delete;
    LoadDocumentCommand(LoadDocumentCommandCLI* loadDocumentCommandCLI, DocumentRegister* documentParser);
    LoadDocumentCommand(LoadDocumentCommand& other) = delete;
    LoadDocumentCommand& operator=(LoadDocumentCommand& other) = delete;

    void execute() override;
    string getName() const override;
    void undo() override;

private:
    DocumentRegister* documentRegister;
    LoadDocumentCommandCLI* loadDoucmentCommandCLI;

};