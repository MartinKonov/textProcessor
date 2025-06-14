#pragma once
#include "CommandsCLI.hpp"

/**
 * @file ScrambleCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the ScrambleCommand.
 */
class ScrambleCommandCLI : public CommandsCLI {
public:
    ScrambleCommandCLI() = default;
    ~ScrambleCommandCLI() override = default;

    void success() override;
    void error(string message = "") override;
    void nothingToUndo();
    void errorActiveDocument();
    void successUndo();
};