/**
 * @file InsertLineCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the InsertLineCommand.
 */
#pragma once
#include "CommandsCLI.hpp"



/**
 * @class InsertLineCommandCLI
 * @brief A class to handle input and output operations for the InsertLineCommand.
 */
class InsertLineCommandCLI : public CommandsCLI {
public:
    InsertLineCommandCLI() = default;
    ~InsertLineCommandCLI() override = default;

    void success() override;
    void showDocumentWithIndices(string document);
    void successUndo();
    string getLineToInsert();
    int getLineNumberToInsert();
};