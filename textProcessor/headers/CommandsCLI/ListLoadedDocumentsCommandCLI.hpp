/**
 * @file ListLoadedDocumentsCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the ListLoadedDocumentsCommand.
 */
#pragma once
#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the ListLoadedDocumentsCommand.
 */
class ListLoadedDocumentsCommandCLI : public CommandsCLI {

    public:
        ListLoadedDocumentsCommandCLI() = default;
        ~ListLoadedDocumentsCommandCLI() override = default;

        void success() override;
        void listDocuments(string documentList);

};