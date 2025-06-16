/**
 * @file ExitCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the ExitCommand.
 */
#pragma once
#include "CommandsCLI.hpp"


/**
 * @class ExitCommandCLI
 * @brief A class to handle input and output operations for the ExitCommand.
 */
class ExitCommandCLI : public CommandsCLI {
public:
    ExitCommandCLI() = default;
    ~ExitCommandCLI() override = default;

    void success() override {};
    void error(string message = "") override {};
    void showDocumentHasChangedMessage(string docName);
    bool getDocumentSaveConfirmation();
};

