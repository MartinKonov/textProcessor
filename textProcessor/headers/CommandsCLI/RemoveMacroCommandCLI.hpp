#pragma once

#include "CommandsCLI.hpp"

/**
 * @file RemoveMacroCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the RemoveMacroCommand.
 */
class RemoveMacroCommandCLI : public CommandsCLI {
public:
    RemoveMacroCommandCLI() = default;
    ~RemoveMacroCommandCLI() override = default;

    void success() override;
    void successUndo();
    void showCurrentMacros(string serializedMacros);
    string getMacroName();
};