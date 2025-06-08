#pragma once

#include "CommandsCLI.hpp"



class SetActiveDocumentCommandCLI : public CommandsCLI {

    public:
        SetActiveDocumentCommandCLI() = default;
        ~SetActiveDocumentCommandCLI() override = default;

        void success() override;
        void error(string message= "") override;
        
        string getDocPath();
        void errorUndoPrevDocName();
        void errorUndo(string message);

};