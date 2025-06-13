#pragma once
#include "Command.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../Document/DocumentRegister.hpp"
#include "../CommandsCLI/ViewDocumentCommandCLI.hpp"
#include "../Formatter/ActiveFormatter.hpp"

class ViewDocumentCommand : public Command {

    public:
        ViewDocumentCommand() = delete;
        ViewDocumentCommand(ViewDocumentCommandCLI* cli, ActiveFormatter* activeFormatter, ActiveDocument* activeDocument, DocumentRegister* documentRegister);
        ViewDocumentCommand(ViewDocumentCommand& other) = delete;
        ViewDocumentCommand& operator=(ViewDocumentCommand& other) = delete;

        string getName() const override;
        void execute() override;
        void undo() override;
        bool isUndoable() const override;

    private:
        ViewDocumentCommandCLI* cli;
        ActiveDocument* activeDocument;
        ActiveFormatter* activeFormatter;
        DocumentRegister* documentRegister;

        bool ACTIVE_DOC_CHOICE = 0;
        bool OTHER_DOC_CHOICE = 1;
};