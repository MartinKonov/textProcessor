/**
 * @file  SaveAsCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the SaveAsCommand.
 */
#pragma once

#include "CommandsCLI.hpp"

/**
 * @brief A class to handle input and output operations for the SaveAsCommand.
 */
class SaveAsCommandCLI : public CommandsCLI {

    public:
        SaveAsCommandCLI() = default;
        ~SaveAsCommandCLI() override = default;

        void success() override;
        void documentHasntChanged();
        void error(string message = "") override;
        string getNewDocName();
};