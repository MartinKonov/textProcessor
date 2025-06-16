/**
 * @file ChangeLineCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the ChangeLineCommand.
 */
#pragma once
#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the ChangeLineCommand.
 */
class ChangeLineCommandCLI : public CommandsCLI {
public:
    ChangeLineCommandCLI() = default;
    ~ChangeLineCommandCLI() override = default;

    void success() override;
    void successUndo();
    void showDocumentWithIndices(string document);
    string getNewLineContent();
    int getLineNumberToChange();
};