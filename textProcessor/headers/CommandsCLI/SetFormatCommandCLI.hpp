/**
 * @file SetFormatCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the SetFormatCommand.
 */
#pragma once
#include "CommandsCLI.hpp"

/**
 * @class SetFormatCommandCLI
 */
class SetFormatCommandCLI : public CommandsCLI {
    public:
        SetFormatCommandCLI() = default;
        ~SetFormatCommandCLI() override = default;

        void success() override;
        void error(string message = "") override;
        
        string getFormatterType(string currentFormatterType);
        int getFormatPoint();
        void successUndo();
};
