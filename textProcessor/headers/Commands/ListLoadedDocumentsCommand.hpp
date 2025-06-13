#pragma once
#include "Command.hpp"
#include "../CommandsCLI/ListLoadedDocumentsCommandCLI.hpp"
#include "../Document/DocumentRegister.hpp"



class ListLoadedDocumentsCommand : public Command {

    public:
        ListLoadedDocumentsCommand() = delete;
        ListLoadedDocumentsCommand(ListLoadedDocumentsCommandCLI* cli, DocumentRegister* documentRegister);
        ListLoadedDocumentsCommand(ListLoadedDocumentsCommand& other) = delete;
        ListLoadedDocumentsCommand& operator=(ListLoadedDocumentsCommand& other) = delete;
        ~ListLoadedDocumentsCommand() override = default;

        string getName() const override;
        void execute() override;
        void undo() override;
        bool isUndoable() const override;

        private:
        ListLoadedDocumentsCommandCLI* cli;
        DocumentRegister* documentRegister;
};
