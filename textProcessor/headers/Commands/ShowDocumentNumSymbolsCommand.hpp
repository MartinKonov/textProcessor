/**
 * @file ShowDocumentNumSymbolsCommand.hpp
 * @author MK
 * @brief A command to show the number of symbols in the active document.
 */
#pragma once

#include "Command.hpp"
#include "../CommandsCLI/ShowDocumentNumSymbolsCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"


/**
 * @class ShowDocumentNumSymbolsCommand
 * @brief A command to show the number of symbols in the active document.
 */

 class ShowDocumentNumSymbolsCommand : public Command {
    public:
        ShowDocumentNumSymbolsCommand() = delete;
        ShowDocumentNumSymbolsCommand(ShowDocumentNumSymbolsCommandCLI* cli, ActiveDocument* activeDocument);
        ~ShowDocumentNumSymbolsCommand() override = default;
    
        ShowDocumentNumSymbolsCommand(const ShowDocumentNumSymbolsCommand& other) = delete;
        ShowDocumentNumSymbolsCommand& operator=(const ShowDocumentNumSymbolsCommand& other) = delete;
    
        string getName() const override;
        void execute() override;
        void undo() override {};
        bool isUndoable() const override;

    private:
        ShowDocumentNumSymbolsCommandCLI* cli;
        ActiveDocument* activeDocument;
 };