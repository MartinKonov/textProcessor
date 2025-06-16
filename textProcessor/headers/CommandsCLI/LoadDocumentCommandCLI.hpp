/**
 * @file LoadDocumentCommandCLI.cpp
 * @author MK
 * @brief A class to handle input and output operations for the LoadDocumentCommand.
 */
#pragma once
#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the LoadDocumentCommand.
 */
class LoadDocumentCommandCLI : public CommandsCLI {

    public:
        LoadDocumentCommandCLI() = default;
        ~LoadDocumentCommandCLI() override = default;
        
        void success() override;
        string getDocFilePath();
};
