#pragma once
#include "CommandsCLI.hpp"


class ViewDocumentCommandCLI : public CommandsCLI {

    public:
        ~ViewDocumentCommandCLI() override = default;
        
        void success() override {};
        int getChoiceActiveDocOrOtherDoc();
        string getDocumentToPrint();
        void printContents(string contentsToPrint);
};
