/**
 * @file SaveCommand.hpp
 * @author MK
 * @brief A command to save the active document in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../CommandsCLI/SaveCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../Document/DocumentRegister.hpp"


/**
 * @brief A command to save the active document in the text processor application.
 */
class SaveCommand : public Command {

    public:
        SaveCommand() = delete;
        SaveCommand(ActiveDocument* activeDocument, SaveCommandCLI* saveCommandCLI,DocumentRegister* documentRegister);
        SaveCommand(const SaveCommand& other) = delete;
        SaveCommand& operator=(const SaveCommand &other) = delete;
        ~SaveCommand() override = default;

        string getName() const override;
        void execute() override;
        void undo() override {};
        bool isUndoable() const override;
    private:
        ActiveDocument* activeDocument;
        DocumentRegister* documentRegister;
        SaveCommandCLI* saveCommandCLI;

};