/**
 * @file SaveCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the SaveCommand.
 */
#pragma once

#include "CommandsCLI.hpp"

/**
 * @brief A class to handle input and output operations for the SaveCommand.
 */
class SaveCommandCLI : public CommandsCLI {

    public:
        SaveCommandCLI() = default;
        ~SaveCommandCLI() override = default;

        void success() override;
        void documentHasntChanged();
        void error(string message = "") override;
};