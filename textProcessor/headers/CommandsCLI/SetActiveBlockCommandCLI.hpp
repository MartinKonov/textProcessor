#pragma once
#include "CommandsCLI.hpp"

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