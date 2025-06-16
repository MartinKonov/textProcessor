/**
 * @file RemoveBlockCommand.hpp
 * @author MK
 * @brief A command to remove a block in the text processor application.
 */
#pragma once
#include "Command.hpp"
#include "../Block/BlockRegister.hpp"
#include "../CommandsCLI/RemoveBlockCommandCLI.hpp"
#include "../Document/DocumentRegister.hpp"

/**
 * @brief A command to remove a block in the text processor application.
 */
class RemoveBlockCommand : public Command {

 public:
    RemoveBlockCommand() = delete;
    RemoveBlockCommand(RemoveBlockCommandCLI* cli,BlockRegister* blockRegister, DocumentRegister* documentRegister);
    RemoveBlockCommand(RemoveBlockCommand& other) = delete;
    RemoveBlockCommand& operator=(RemoveBlockCommand& other) = delete;
    ~RemoveBlockCommand() override;

    string getName() const override;
    void execute() override;
    void undo() override;

 private:
    Block* removedBlock;
    BlockRegister* blockRegister;
    RemoveBlockCommandCLI* cli;
    DocumentRegister* documentRegister;
};