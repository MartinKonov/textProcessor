/**
 * @file SetActiveDocumentCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the SetActiveDocumentCommand.
 */
#pragma once

#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the SetActiveDocumentCommand.
 */
class SetActiveDocumentCommandCLI : public CommandsCLI {

    public:
        SetActiveDocumentCommandCLI() = default;
        ~SetActiveDocumentCommandCLI() override = default;

        void success() override;
        string getDocPath();
};