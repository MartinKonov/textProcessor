#pragma once
#include "CommandsCLI.hpp"



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