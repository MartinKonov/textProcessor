/**
 * @file UnloadDocumentCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the UnloadDocumentCommand.
 */
#pragma once
#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the UnloadDocumentCommand.
 */
class UnloadDocumentCommandCLI : public CommandsCLI {

public:
    UnloadDocumentCommandCLI() = default;
    ~UnloadDocumentCommandCLI() override = default;

    void success() override;
    void error(string message = "") override;
    string getDocPathToUnload();
    void docHasChanged();
    bool saveQuery();

};