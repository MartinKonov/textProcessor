/**
 * @file ToLowerCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the ToLowerCommand.
 */
#pragma once
#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the ToLowerCommand.
 */
class ToLowerCommandCLI : public CommandsCLI {
public:
    ToLowerCommandCLI() = default;
    ~ToLowerCommandCLI() override = default;

    void success() override;
    void error(string message = "") override;
    void nothingToUndo();
    void successUndo();
};