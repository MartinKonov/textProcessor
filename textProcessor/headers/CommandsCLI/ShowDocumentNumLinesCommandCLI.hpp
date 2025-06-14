/**
 * @file ShowDocumentNumLinesCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the ShowDocumentNumLinesCommand.
 */
#pragma once
#include "CommandsCLI.hpp"

/**
 * @file ShowDocumentNumLinesCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the ShowDocumentNumLinesCommand.
 */
class ShowDocumentNumLinesCommandCLI : public CommandsCLI {
public:
    ShowDocumentNumLinesCommandCLI() = default;
    ~ShowDocumentNumLinesCommandCLI() override = default;

    void success() override {};
    void error(string message = "") override;
    void showNumLines(int numLines);
};