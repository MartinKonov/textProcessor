/**
 * @file TrimTrailingCommandCLI.hpp
 * @author MK
 * @brief Command Line Interface (CLI) for the Trim Trailing Command.
 */
#pragma once
#include "CommandsCLI.hpp"

/**
 * @class TrimTrailingCommandCLI
 * @brief A class to handle input and output operations for the Trim Trailing Command.
 */
class TrimTrailingCommandCLI : public CommandsCLI {
public:
    TrimTrailingCommandCLI() = default;
    ~TrimTrailingCommandCLI() override = default;

    void success() override;
    void error(string message = "") override;
    void nothingToUndo();
    void noActiveDocumentSet();
};