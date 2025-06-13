#pragma once
#include "CommandsCLI.hpp"



class ListLoadedDocumentsCommandCLI : public CommandsCLI {

    public:
        ListLoadedDocumentsCommandCLI() = default;
        ~ListLoadedDocumentsCommandCLI() override = default;

        void success() override;
        void error(string message = "") override;
        void listDocuments(string documentList);

};