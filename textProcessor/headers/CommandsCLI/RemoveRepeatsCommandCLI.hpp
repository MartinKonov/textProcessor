/**
 * @file RemoveRepeatsCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the RemoveRepeatsCommand.
 */
#pragma once
#include "CommandsCLI.hpp"

/**
 * @class RemoveRepeatsCommandCLI
 * @brief A class to handle input and output operations for the RemoveRepeatsCommand.
 */
class RemoveRepeatsCommandCLI : public CommandsCLI {
public:
    RemoveRepeatsCommandCLI() = default;
    ~RemoveRepeatsCommandCLI() override = default;

    void success() override;
    void error(string message = "") override;
    void nothingToUndo();
    void errorActiveDocument();
    void successUndo();
};