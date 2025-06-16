/**
 * @file ShowDocumentNumSymbolsCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the ShowDocumentNumSymbolsCommand.
 */
#pragma once

#include "CommandsCLI.hpp"



/**
 * @class ShowDocumentNumSymbolsCommandCLI
 * @brief A class to handle input and output operations for the ShowDocumentNumSymbolsCommand.
 */
class ShowDocumentNumSymbolsCommandCLI : public CommandsCLI {
    public:
        ShowDocumentNumSymbolsCommandCLI() = default;
        ~ShowDocumentNumSymbolsCommandCLI() override = default;

        void showNumSymbols(int numSymbols);
        void success() override {};
};