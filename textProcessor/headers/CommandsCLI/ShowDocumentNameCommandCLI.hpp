#pragma once
#include "CommandsCLI.hpp"
/**
 * @file ShowDocumentNameCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for showing the name of the active document.
 */
class ShowDocumentNameCommandCLI : public CommandsCLI {
public:
    ShowDocumentNameCommandCLI() = default;
    ~ShowDocumentNameCommandCLI() override = default;

    void success() override;
    void error(string message = "") override;
    void showDocumentName(string documentName);
};