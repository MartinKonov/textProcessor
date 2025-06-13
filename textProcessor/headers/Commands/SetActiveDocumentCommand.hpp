/**
 * @file SetActiveDocumentCommand.hpp
 * @author MK
 * @brief A command to set the active document in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../CommandsCLI/SetActiveDocumentCommandCLI.hpp"

/**
 * @brief A command to set the active document in the text processor application.
 */
class SetActiveDocumentCommand : public Command {

public: 
    SetActiveDocumentCommand() = delete;
    SetActiveDocumentCommand(SetActiveDocumentCommandCLI* setActiveDocumentCLI, ActiveDocument* activeDocument);
    SetActiveDocumentCommand(SetActiveDocumentCommand& other) = delete;
    SetActiveDocumentCommand& operator=(SetActiveDocumentCommand& other) = delete;
    ~SetActiveDocumentCommand() override = default;
    
    void execute() override;
    void undo() override;
    string getName() const override;

private:
    ActiveDocument* activeDocument;
    SetActiveDocumentCommandCLI* setActiveDocumentCLI;
    string previousActiveDocumentName;
};