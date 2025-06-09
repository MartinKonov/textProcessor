#pragma once
#include "Command.hpp"
#include "../CommandsCLI/SaveAsCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"
#include "../Document/DocumentRegister.hpp"

class SaveAsCommand: public Command {
public:
    SaveAsCommand() = delete;
    SaveAsCommand(ActiveDocument* activeDocument, SaveAsCommandCLI* saveAsCommandCLI,DocumentRegister* documentRegister): activeDocument(activeDocument),saveAsCommandCLI(saveAsCommandCLI), documentRegister(documentRegister) {}
    SaveAsCommand(const SaveAsCommand& other) = delete;
    SaveAsCommand& operator=(const SaveAsCommand &other) = delete;
    ~SaveAsCommand() override = default;

    string getName() const override;
    void execute() override;
    void undo() override;

private:
    ActiveDocument* activeDocument;
    DocumentRegister* documentRegister;
    SaveAsCommandCLI* saveAsCommandCLI;
};