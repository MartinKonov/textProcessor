#pragma once
#include "CommandsCLI.hpp"



class LoadDocumentCommandCLI : public CommandsCLI {

    public:
        LoadDocumentCommandCLI() = default;
        ~LoadDocumentCommandCLI() = default;
        
        void success() override;
        string getDocFilePath();
        void error(string errorMessage);
        void undo();
};