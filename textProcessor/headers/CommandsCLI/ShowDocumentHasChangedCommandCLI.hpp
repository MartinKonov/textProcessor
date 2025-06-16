/**
 * @file ShowDocumentHasChangedCommandCLI.hpp
 * @author MK
 * @brief A command to show whether the active document has changed.
 */

#pragma once
#include "CommandsCLI.hpp"


/**
 * @class ShowDocumentHasChangedCommandCLI
 * @brief A class to handle input and output operations for the ShowDocumentHasChangedCommand.
 */
class ShowDocumentHasChangedCommandCLI : public CommandsCLI {
public:
    ShowDocumentHasChangedCommandCLI() = default;
    ~ShowDocumentHasChangedCommandCLI() override = default;

    void success() override {};
    void showDocumentHasChanged(bool hasChanged);
    
};