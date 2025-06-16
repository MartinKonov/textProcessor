/**
 * @file TrimLeadingCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the TrimLeadingCommand.
 */

#pragma once
#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the TrimLeadingCommand.
 */
class TrimLeadingCommandCLI : public CommandsCLI {
public:
    TrimLeadingCommandCLI() = default;
    ~TrimLeadingCommandCLI() override = default;

    void success() override;
    void successUndo();
};