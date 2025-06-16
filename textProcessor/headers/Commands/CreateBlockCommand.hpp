/**
 * @file CreateBlockCommand.hpp
 * @author MK
 * @brief A command to create a block in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../Block/BlockRegister.hpp"
#include "../CommandsCLI/CreateBlockCommandCLI.hpp"
#include "../Document/ActiveDocument.hpp"


/**
 * @brief A command to create a block in the text processor application.
 */
class CreateBlockCommand : public Command {

 public:
    CreateBlockCommand() = delete;
    CreateBlockCommand(CreateBlockCommandCLI* cli, BlockRegister* blockRegister, ActiveDocument* activeDocument);
    CreateBlockCommand(CreateBlockCommand& other) = delete;
    CreateBlockCommand& operator=(CreateBlockCommand& other) = delete;
    ~CreateBlockCommand() override = default;

    string getName() const override;
    void execute() override;
    void undo() override;

 private:
    string nameOfLastBlockCreated;
    BlockRegister* blockRegister;
    CreateBlockCommandCLI* cli;
    ActiveDocument* activeDocument;
};