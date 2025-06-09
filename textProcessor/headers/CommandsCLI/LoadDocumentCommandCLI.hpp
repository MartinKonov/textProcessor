#pragma once
#include "CommandsCLI.hpp"



class LoadDocumentCommandCLI : public CommandsCLI {

    public:
        LoadDocumentCommandCLI() = default;
        ~LoadDocumentCommandCLI() override = default;
        
        void success() override;
        string getDocFilePath();
        void error(string message = "") override;
        void undo();
};