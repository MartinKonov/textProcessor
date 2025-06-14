/**
 * @file RemoveLineCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the RemoveLineCommand.
 */
#pragma once
#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the RemoveLineCommand.
 */
class RemoveLineCommandCLI : public CommandsCLI {
public:
    RemoveLineCommandCLI() = default;
    ~RemoveLineCommandCLI() override = default;

    void success() override;
    void successUndo();

    void error(string message = "") override;
    void showDocumentWithIndices(string documentContents);
    string getLineNumberToRemove();
};