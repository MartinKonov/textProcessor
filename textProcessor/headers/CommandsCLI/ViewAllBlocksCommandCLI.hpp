#pragma once
#include "CommandsCLI.hpp"


class ViewAllBlocksCommandCLI : public CommandsCLI {

    public:
    ViewAllBlocksCommandCLI() = default;
    ~ViewAllBlocksCommandCLI() override = default;

    void success() override;
    void error(string message = "") override;

    void showBlocksForActiveDoc(string blocksForDocSerialized);
};