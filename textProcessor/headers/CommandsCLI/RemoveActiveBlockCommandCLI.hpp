/**
 * @file RemoveActiveBlockCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the RemoveActiveBlockCommand.
 */
#pragma once
#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the RemoveActiveBlockCommand.
 */
class RemoveActiveBlockCommandCLI : public CommandsCLI {
 public:
    RemoveActiveBlockCommandCLI() = default;
    ~RemoveActiveBlockCommandCLI() override = default;

    void success() override;
};