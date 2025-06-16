/**
 * @file ViewAllBlocksCommandCLI.hpp
 * @author MK
 * @brief A class to handle input and output operations for the ViewAllBlocksCommand.
 */
#pragma once
#include "CommandsCLI.hpp"


/**
 * @brief A class to handle input and output operations for the ViewAllBlocksCommand.
 */
class ViewAllBlocksCommandCLI : public CommandsCLI {

    public:
    ViewAllBlocksCommandCLI() = default;
    ~ViewAllBlocksCommandCLI() override = default;

    void success() override {};

    void showBlocksForActiveDoc(string blocksForDocSerialized);
};