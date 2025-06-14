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
        void error(string message = "") override;

        void errorActiveDocument();
        void showBlocksForActiveDoc(string blocksForDocSerialized);
        string getNewActiveBlockName();
        void nothingToUndo();
        void documentHasChanged();
        void errorUndo(string message);
};