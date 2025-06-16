/**
 * @file SetActiveBlockCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the SetActiveBlockCommand.
 */
#pragma once
#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the SetActiveBlockCommand.
 */
class SetActiveBlockCommandCLI : public CommandsCLI {

    public:
        SetActiveBlockCommandCLI() = default;
        ~SetActiveBlockCommandCLI() override = default;

        void success() override;
        void showBlocksForActiveDoc(string blocksForDocSerialized);
        string getNewActiveBlockName();
};