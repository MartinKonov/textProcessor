/**
 * @file ToUpperCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the ToUpperCommand.
 */
#pragma once
#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the ToUpperCommand.
 */
class ToUpperCommandCLI : public CommandsCLI {
public:
    ToUpperCommandCLI() = default;
    ~ToUpperCommandCLI() override = default;

    void success() override;
    void successUndo();
};