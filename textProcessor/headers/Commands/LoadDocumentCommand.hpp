/**
 * @file LoadDocumentCommand.hpp
 * @author MK
 * @brief A command to load a document in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../CommandsCLI/LoadDocumentCommandCLI.hpp"
#include "../Document/DocumentRegister.hpp"



/**
 * @brief A command to load a document in the text processor application.
 */
class LoadDocumentCommand : public Command {

public:
    LoadDocumentCommand() = delete;
    LoadDocumentCommand(LoadDocumentCommandCLI* cli, DocumentRegister* documentParser);
    LoadDocumentCommand(LoadDocumentCommand& other) = delete;
    LoadDocumentCommand& operator=(LoadDocumentCommand& other) = delete;
    ~LoadDocumentCommand() override = default;

    void execute() override;
    string getName() const override;
    void undo() override {};
    bool isUndoable() const override;

private:
    DocumentRegister* documentRegister;
    LoadDocumentCommandCLI* cli;

};