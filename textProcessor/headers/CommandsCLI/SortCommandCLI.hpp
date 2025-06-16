/**
 * @file SortCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the SortCommand.
 */

#pragma once
#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the SortCommand.
 */
class SortCommandCLI : public CommandsCLI {

    public:
    SortCommandCLI() = default;
    ~SortCommandCLI() override = default;

    void success() override;
    void successUndo();
};