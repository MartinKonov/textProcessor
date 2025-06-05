#pragma once
#include "Command.hpp"
#include "../CommandsCLI/SaveCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../Document/DocumentRegister.hpp"



class SaveCommand : public Command {

    public:
        SaveCommand() = delete;
        SaveCommand(ActiveDocument* activeDocument, SaveCommandCLI* saveCommandCLI,DocumentRegister* documentRegister);
        SaveCommand(const SaveCommand& other) = delete;
        SaveCommand& operator=(const SaveCommand &other) = delete;

        string getName() const override;
        void execute() override;
        void undo() override;

    private:
        ActiveDocument* activeDocument;
        DocumentRegister* documentRegister;
        SaveCommandCLI* saveCommandCLI;

};